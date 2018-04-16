#include "header.h"

class Solution {
public:
    int racecar(int target) {
        static vector<int> dp(10001, -1);
        return impl(target, dp);
    }

    int impl(int target, vector<int>& dp)
    {
        if(dp[target] > 0) return dp[target];
        int n = ceil(log2(target + 1));
        if(1 << n == target + 1) dp[target] = n;
        else
        {
            dp[target] = impl((1 << n) - 1 - target, dp) + (n + 1);
            for(int i = 0; i < n - 1; ++i)
            {
                dp[target] = min(dp[target], impl(target - (1 << (n - 1)) + (1 << i), dp) + (n + i + 1));
            }
        }
        return dp[target];
    }
};

int main()
{
    Solution s;
    //std::cout<<s.racecar(3)<<std::endl;
    //std::cout<<s.racecar(6)<<std::endl;
    std::cout<<s.racecar(5)<<std::endl;
    std::cout<<s.racecar(4)<<std::endl;
    std::cout<<s.racecar(11)<<std::endl;
}
