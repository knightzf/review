#include "header.h"

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> m;
        for(const auto& w : words) m[w.size()].push_back(w);
        unordered_map<string, int> countMap;
        int res = 1;
        for(const auto& p : m){
            for(const auto& w : p.second) {
                countMap[w] = 1;
                if(p.first > 1) {
                    for(const auto& y : m[p.first - 1]) {
                        if(valid(w, y)) {
                            countMap[w] = max(countMap[w], countMap[y] + 1);
                        }
                    }
                }
                res = max(res, countMap[w]);
            }
        }
        return res;
    }

    bool valid(const string& a, const string& b) {
        int misMatch = 0;
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while(i < m) {
            if(a[i] != b[j]) {
                if(misMatch) return false;
                ++i;
                ++misMatch;
            } else {
                ++i; ++j;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
}

