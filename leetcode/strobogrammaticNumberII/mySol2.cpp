#include "header.h"

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        static unordered_map<char, char> m{
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'},
        };
        if(n == 0) return {};
        if(n == 1) return {"0", "1", "8"};

        int mid = (n - 1) / 2;
        string s;
        vector<string> res;

        function<void(int)> dfs = [&](int idx)
        {
            if(idx > mid) {
                string t = s;
                int i = (n & 1) ? mid - 1 : mid;
                int j = idx;
                while(i >= 0) {
                    t += m[t[i--]];
                }
                res.emplace_back(t);
                return;
            }

            for(auto& p : m) {
                if(idx == 0 && p.first == '0') continue;
                if((n & 1) && idx == mid && (p.first == '6' || p.first == '9')) continue;
                s += p.first;
                dfs(idx + 1);
                s.pop_back();
            }
        };

        dfs(0);
        return res;
    }
};

int main()
{
    Solution s;
}