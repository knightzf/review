#include "header.h"

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 1000);
        dp[1] = 0;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(i % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + 1 + i / j - 1);
                }
            }
        }
        for(int i : dp)
            cout<<i<<" ";
        cout<<endl;
        return dp[n];
    }
};

int main() {
    Solution s;
    s.minSteps(4);
}
