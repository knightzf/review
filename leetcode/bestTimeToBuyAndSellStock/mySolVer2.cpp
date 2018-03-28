#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMin = INT_MAX;
        int maxP = 0;
        for(int i = 0; i < n; ++i)
        {
            currMin = min(currMin, prices[i]);
            if(currMin < prices[i]) maxP = max(maxP, prices[i] - currMin);
        }
        return maxP;
    }
};

int main()
{
    Solution s;
}
