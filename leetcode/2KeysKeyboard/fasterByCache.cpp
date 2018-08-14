#include "header.h"

class Solution {
public:
    int minSteps(int n) {
        static vector<int> dp(1001, 1000);
        if(dp[1] == 1000)
        {
            dp[1] = 0;

            for(int i = 2; i <= 1000; ++i)
            {
                for(int j = 1; j < i; ++j)
                {
                    if(i % j == 0)
                    {
                        dp[i] = min(dp[i], dp[j] + 1 + i / j - 1);
                    }
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution s;
    s.minSteps(4);
}
