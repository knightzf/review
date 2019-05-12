#include "header.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        static unordered_map<int, vector<string>> m {
            {0, {}},
            {1, {"()"}}
        };

        if(m.count(n)) return m[n];

        vector<string> res;
        for(int i = 1; i <= n; ++i)
        {
            auto left = generateParenthesis(i - 1);
            if(left.empty()) left.emplace_back("()");
            else {
                for(auto& s : left) s = '(' + s + ')';
            }            

            const auto& right = generateParenthesis(n - i);
            if(right.empty()) res.insert(res.end(), left.begin(), left.end());
            else
            {
                for(const auto& s : left)
                {
                    for(const auto& p : right)
                    {
                        res.emplace_back(s + p);
                    }
                }
            }
        }
        m[n] = res;
        return res;
    }
};

int main()
{
    Solution s;
}