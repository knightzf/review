#include "header.h"

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        int m = pattern.size(), n = str.size();
        unordered_map<char, int> charMap;
        for(int i = 0; i < m; ++i) {
            if(!charMap.count(pattern[i])) {
                charMap[pattern[i]] = i;
            }
        }
        unordered_map<char, string> mapping;
        unordered_set<string> subs;
        function<bool(int, int)> dfs = [&](int pIdx, int sIdx) {
            if(pIdx == m && sIdx == n) return true;
            if(pIdx == m || sIdx == n) return false;
            if(mapping.count(pattern[pIdx])) {
                const auto& t = mapping[pattern[pIdx]];
                if(sIdx + t.size() <= n && str.substr(sIdx, t.size()) == t) {
                    return dfs(pIdx + 1, sIdx + t.size());
                }
                return false;
            } else {
                for(int len = 1; len <= n - sIdx; ++len) {
                    const auto& t = str.substr(sIdx, len);
                    if(subs.count(t)) continue;
                    mapping[pattern[pIdx]] = str.substr(sIdx, len);
                    subs.insert(t);
                    if(dfs(pIdx + 1, sIdx + len)) return true;
                    mapping.erase(pattern[pIdx]);
                    subs.erase(t);
                }
            }
            return false;
        };
        return dfs(0, 0);
    }
};

int main()
{
    Solution s;
}