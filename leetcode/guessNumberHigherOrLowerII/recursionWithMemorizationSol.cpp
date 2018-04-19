#include "header.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return impl(1, n, dp);
    }

    int impl(int l, int r, vector<vector<int>>& dp)
    {
        if(l == r) return 0;
        if(l + 1 == r) return l;
        if(dp[l][r] != -1) return dp[l][r];

        int res = INT_MAX;
        for(int i = l + (r - l) / 2; i < r; ++i)
        {
            res = min(res, i + max(impl(l, i - 1, dp), impl(i + 1, r, dp)));
        }

        dp[l][r] = res;
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.getMoneyAmount(4)<<std::endl;
    std::cout<<s.getMoneyAmount(5)<<std::endl;
    std::cout<<s.getMoneyAmount(7)<<std::endl;
    std::cout<<s.getMoneyAmount(100)<<std::endl;
}
