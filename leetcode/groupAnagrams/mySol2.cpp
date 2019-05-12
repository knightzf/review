#include "header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(const auto& w : strs)
        {
            map<char, int> cnt;
            for(char c : w) ++cnt[c];
            string key;
            for(const auto& p : cnt)
            {
                key += p.first + to_string(p.second);
            }
            m[key].emplace_back(w);
        }
        vector<vector<string>> res;
        for(const auto& p : m)  res.emplace_back(p.second);
        return res;
    }
};

int main()
{
    Solution s;
}