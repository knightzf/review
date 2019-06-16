#include "header.h"

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<int, unordered_map<string, vector<string>>> m;
        for(const auto& s : strings) {
            int n = s.size();
            stringstream key;
            key << "0|";
            for(int i = 1; i < n; ++i) {
                int t = s[i] - s[0];
                if(t < 0) t += 26;
                key << t << "|";
            }
            m[n][key.str()].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& p : m)
            for(const auto& q : p.second)
                res.emplace_back(q.second);
        return res;
    }
};

int main()
{
    Solution s;
}