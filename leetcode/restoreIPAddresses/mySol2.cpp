#include "header.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        vector<string> t;
        function<void(int, int)> dfs = [&](int idx, int sections)
        {
            if((n - idx) > sections * 3 || (n - idx) < sections) return;
            if(idx == n && sections == 0) {
                res.emplace_back(t[0] + '.' + t[1] + '.' + t[2] + '.' + t[3]);
                return;
            }

            t.emplace_back(s.substr(idx, 1));
            dfs(idx + 1, sections - 1);
            t.pop_back();

            if(idx + 2 <= n) {
                int tt = stoi(s.substr(idx, 2));
                if(tt >= 10) {
                    t.emplace_back(s.substr(idx, 2));
                    dfs(idx + 2, sections - 1);
                    t.pop_back();
                }
            }

            if(idx + 3 <= n) {
                int tt = stoi(s.substr(idx, 3));
                if(tt >= 100 && tt <= 255) {
                    t.emplace_back(s.substr(idx, 3));
                    dfs(idx + 3, sections - 1);
                    t.pop_back();
                }
            }
        };

        dfs(0, 4);
        return res;
    }
};

int main()
{
    Solution s;
}