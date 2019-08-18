#include "header.h"

class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        vector<vector<int>> v(26);
        for(int i = 0; i < n; ++i) {
            if(i == 0 || s[i] != s[i - 1])
            v[s[i] - 'a'].push_back(i);
        }
        vector<pair<string, int>> sv;
        for(int i = 25; i >= 0; --i) {
            if(!v[i].empty()) {
                for(int j : v[i]) sv.push_back({string(1, 'a' + i), j});
                break;
            }
        }
        while(sv.size() > 1) {
            vector<pair<string, int>> t;
            for(const auto& p : sv) {
                string str = p.first;
                int idx = p.second;
                if(idx < n - 1) str += s[++idx];
                if(!t.empty() && str < t.back().first) continue;
                while(!t.empty() && str > t.back().first) t.pop_back();
                t.push_back({str, idx});
            }
            swap(sv, t);
        }
        return sv[0].first + s.substr(sv[0].second + 1);
    }
};

int main()
{
    Solution s;
    s.lastSubstring("abab");
}
