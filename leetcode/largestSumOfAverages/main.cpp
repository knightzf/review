#include "header.h"

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> sum(n);
        for(int i = 0; i < n; ++i)
            sum[i] = i == 0 ? A[i] : (A[i] + sum[i - 1]);

        vector<vector<double>> dp(n, vector<double>(K + 1, 0));
        for(int i = 0; i < n; ++i)
        {
            dp[i][1] = sum[i] / (i + 1);
        }

        for(int i = 1; i < n; ++i)
        {
            for(int j = 2; j <= K; ++j)
            {
                double t = 0;
                for(int k = i - 1; k >= 0; --k)
                {
                    t = max(t, dp[k][j - 1] + (sum[i] - sum[k]) / (i - k));
                }
                dp[i][j] = t;
            }
        }

        /*for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= K; ++j)
            {
                std::cout<<dp[i][j]<<" ";
            }
            std::cout<<std::endl;
        }*/

        return dp[n - 1][K];
    }
};

int main()
{
    Solution s;
    vector<int> a{9,1,2,3,9};
    std::cout<<s.largestSumOfAverages(a, 3)<<std::endl;
}
