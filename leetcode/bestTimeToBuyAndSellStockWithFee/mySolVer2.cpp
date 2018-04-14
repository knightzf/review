#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.empty()) return 0;
        int n = prices.size();
        int ownStock = -prices[0];
        int noStock = 0;

        for(int i = 1; i < n; ++i)
        {
            ownStock = max(ownStock, noStock - prices[i]);
            noStock = max(noStock, prices[i] + ownStock - fee);
        }

        return noStock;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 3, 2, 8, 4, 9};
    std::cout<<s.maxProfit(a, 2)<<std::endl;
}
