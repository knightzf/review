#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool hasStock = false;
        int cost = INT_MAX;
        int res = 0;
        for(int i = 0, n = prices.size(); i < n; ++i)
        {
            if((i > 0 && prices[i] < prices[i - 1]) || i == n - 1)
            {
                if(prices[i - 1] > cost) res += prices[i - 1] - cost;
                cost = prices[i];
            }
            else
            {
                cost = min(cost, prices[i]);
            }            
        }
        return res;
    }
};

int main()
{
    Solution s;
    
}