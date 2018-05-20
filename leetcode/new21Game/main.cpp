#include "header.h"

class Solution {
public:
    double new21Game(int N, int K, int W) {
        int maxNumber = K + W - 1;
        vector<double> dp(maxNumber + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < maxNumber + 1; ++i)
        {
            dp[i] = dp[i - 1];
            if(i <= W)
            {
                dp[i] += dp[i - 1] / W;
            }
            else
            {
                dp[i] += (dp[i - 1] - dp[i - W - 1]) / W;
            }

            if(i > K)
            {
                dp[i] -= (dp[i - 1] - dp[K - 1]) / W;
            }
        }
        return (dp[N] - dp[K - 1]) / (dp[maxNumber] - dp[K - 1]);
    }
};

int main()
{
    Solution s;
}
