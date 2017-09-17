#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        if(s.empty())
        {
            return 0;
        }

        int len = s.size();
        std::vector<int> dp(len , 0); //max len of valid parenthesis ending s[i]

        for(int i = 1; i < len; ++i)
        {
            int prev = i - 1;
            int furtherPrev = i - 2;

            if(dp[prev] == 0)
            {
                if(s[prev] == '(' && s[i] == ')')
                {
                    dp[i] = 2;

                    if(furtherPrev >= 0 && dp[furtherPrev])
                    {
                        dp[i] += dp[furtherPrev];
                    }
                }
            }
            else
            {
                if(s[i] == ')')
                {
                    int temp = i - dp[prev] - 1;
                    if(temp >= 0 && s[temp] == '(')
                    {
                        dp[i] = dp[prev] + 2;
                    }
                }
            }

            if(dp[i])
            {
                int temp = i - dp[i];
                if(temp >= 0 && dp[temp])
                {
                    dp[i] += dp[temp];
                }
            }
        }

        auto iter = std::max_element(dp.begin(), dp.end());
        return *iter;
    }
};

int main()
{
    Solution sol;
    //std::cout<<sol.longestValidParentheses("(()")<<std::endl;
    //std::cout<<sol.longestValidParentheses(")()())")<<std::endl;
    std::cout<<sol.longestValidParentheses("()(())")<<std::endl;
    return 0;
}
