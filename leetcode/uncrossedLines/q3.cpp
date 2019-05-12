#include "header.h"

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1]));
                }
                res = max(res, dp[i][j]);                
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 4, 2};
    vector<int> b{1, 2, 4};
    cout<<s.maxUncrossedLines(a, b)<<endl;
}

