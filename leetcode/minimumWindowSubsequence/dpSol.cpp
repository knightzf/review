#include "header.h"

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j < m; ++j)
            {
                if(i == 0)
                {
                    if(S[j] == T[i])
                    {
                        dp[i][j] = j;
                    }
                    else
                    {
                        if(j > 0) dp[i][j] = dp[i][j - 1];
                    }
                }
                else
                {
                    if(S[j] == T[i])
                    {
                        dp[i][j] = dp[i- 1][j - 1];
                    }
                    else
                    {
                        if(j > 0) dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        string res;
        for(int j = n - 1; j < m; ++j)
        {
            if(dp[n - 1][j] != -1)
            {
                if(res.empty() || j - dp[n - 1][j] + 1 < res.size())
                {
                    res = S.substr(dp[n - 1][j], j - dp[n - 1][j] + 1);
                }
            }
        }
        return res;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                cout<<T[i]<<" "<<dp[i][j]<<" |";
            }
            cout<<endl;
        }
        return "";
    }
};

int main() {
    Solution s;
    cout<<s.minWindow("abcdebdde", "bde")<<endl;
}
