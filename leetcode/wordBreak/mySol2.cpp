#include "header.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> cache;
        function<bool(int)> dfs = [&](int idx)
        {
            if(idx == n) return true;
            if(!cache.count(idx))
            {
                bool res = false;
                for(int i = idx; i < n; ++i) {
                    if(m.count(s.substr(idx, i - idx + 1)) && dfs(i + 1)) {
                        res = true;
                        break;
                    }
                }
                cache[idx] = res;
            }
            return cache[idx];
        };
        return dfs(0);
    }
};

int main()
{
    Solution s;
    
}