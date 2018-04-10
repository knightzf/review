#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;
        for(int i = 2; i < n + 1; ++i)
        {
            int idx = i - 1;

            if(s[idx] == '0' && (s[idx - 1] != '*' && s[idx - 1] != '1' && s[idx - 1] != '2'))
                return 0;

            if(s[idx] != '*')
            {
                if(s[idx - 1] != '*')
                {
                    dp[i] = s[idx] != '0' ? dp[i - 1] : 0;
                    int t = std::stoi(s.substr(idx - 1, 2));
                    if(t >= 10 && t <= 26) dp[i] += dp[i - 2];
                }
                else
                {
                    dp[i] = (s[idx] != '0' ? dp[i - 1] : 0);
                    int t = s[idx] - '0';
                    if(t >= 0 && t <= 6) dp[i] += dp[i - 2] * 2;
                    else dp[i] += dp[i - 2];
                }
            }
            else
            {
                if(s[idx - 1] != '*')
                {
                    dp[i] = dp[i - 1] * 9;
                    if(s[idx - 1] == '1')
                        dp[i] += dp[i - 2] * 9;
                    else if(s[idx - 1] == '2')
                        dp[i] += dp[i - 2] * 6;
                }
                else
                {
                    dp[i] = dp[i - 1] * 9 + dp[i - 2] * 15;
                }
            }

            dp[i] %= 1000000007;
        }

        /*for(long i : dp)
            std::cout<<i<<" ";
        std::cout<<std::endl;
        //*/

        return dp[n];
    }
};

int main()
{
    Solution s;
    //std::cout<<s.numDecodings("*")<<std::endl;
    //std::cout<<s.numDecodings("1*")<<std::endl;
    //std::cout<<s.numDecodings("126")<<std::endl;
    //std::cout<<s.numDecodings("*10*1")<<std::endl;
    //std::cout<<s.numDecodings("1*72*")<<std::endl;
    //std::cout<<s.numDecodings("*********")<<std::endl;
    std::cout<<s.numDecodings("********************")<<std::endl;
}
