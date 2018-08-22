#include "header.h"

class Solution {
public:
    int strangePrinter(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for(int len = 1; len <= n; ++len)
        {
            for(int i = 0; i <= n - len; ++i)
            {
                if(len == 1)
                {
                    dp[i][i] = 1;
                }                
                else
                {
                    int k = i + len - 1;
                    for(int j = i; j < k; ++j)
                    {                        
                        if(s[j] == s[k])
                        {
                            dp[i][k] = min(dp[i][k],
                                dp[i][j] + (j == k - 1 ? 0 : dp[j + 1][k - 1]));
                        }
                    }
                    dp[i][k] = min(dp[i][k], dp[i][k - 1] + 1);
                }
            }
            /*for(auto i : dp)
            {
                for(auto j : i)
                    cout<<j<<" ";
                cout<<endl;
            }
            cout<<"----"<<endl;*/
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    cout<<s.strangePrinter("aaab")<<endl;
    cout<<s.strangePrinter("aba")<<endl;
    cout<<s.strangePrinter("abcadea")<<endl;
    cout<<s.strangePrinter("tbgtgb")<<endl;
}
