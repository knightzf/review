#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minCost = INT_MAX;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res = max(res, prices[i] - minCost);
            minCost = min(minCost, prices[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    
}