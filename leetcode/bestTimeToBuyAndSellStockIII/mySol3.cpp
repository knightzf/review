#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n, 0), dp2(n, 0);
        int minCost = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            int t = max(prices[i] - minCost, 0);
            dp1[i] = i > 0 ? max(dp1[i - 1], t) : t;
            minCost = min(minCost, prices[i]);
        }
        int maxPrice = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            int t = max(maxPrice - prices[i], 0);
            dp2[i] = i < n - 1 ? max(dp2[i + 1], t) : t;
            maxPrice = max(maxPrice, prices[i]);
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            int t = dp1[i] + (i < n - 1 ? dp2[i + 1] : 0);
            res = max(res, t);
        }
        return res;
    }
};

int main()
{
    Solution s;
    
}