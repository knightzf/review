#include "header.h"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        vector<string> tokens;
        int n = num.size();
        function<void(int, long, long)> dfs = [&](int idx, long curr, long add)
        {
            if(curr > INT_MAX || curr < INT_MIN) return;
            if(idx == n) {
                if(curr == target) {
                    string temp;
                    for(const auto& t : tokens) temp += t;
                    res.emplace_back(temp);
                }
                return;
            }
            for(int len = 1; len <= n - idx; ++len)
            {
                if(num[idx] == '0' && len > 1) return;
                const auto& t = num.substr(idx, len);
                long x = stol(t);
                if(idx == 0) {
                    tokens.emplace_back(t);
                    dfs(idx + len, x, x);
                    tokens.pop_back();
                } else {
                    tokens.emplace_back("+" + t);
                    dfs(idx + len, curr + x, x);
                    tokens.pop_back();
                    tokens.emplace_back("-" + t);
                    dfs(idx + len, curr - x, -x);
                    tokens.pop_back();
                    tokens.emplace_back("*" + t);
                    dfs(idx + len, curr - add + add * x, add * x);
                    tokens.pop_back();
                }
            }
        };
        dfs(0, 0, 0);
        return res;
    }
};

int main()
{
    //Solution s;
}