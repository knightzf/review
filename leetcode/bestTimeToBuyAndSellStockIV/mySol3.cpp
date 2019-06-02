#include "header.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k > prices.size() / 2) {
            int sum = 0;
            for(int i = 1, n = prices.size(); i < n; ++i) {
                if(prices[i] > prices[i - 1]) sum += prices[i] - prices[i - 1];
            }
            return sum;
        }
        k = min(k, (int)prices.size() / 2);
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, INT_MIN); sell[0] = 0;
        for(int i = 0, n = prices.size(); i < n; ++i) {
            for(int j = k; j > 0; --j) {
                if(sell[j - 1] != INT_MIN)
                    buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                if(buy[j] != INT_MIN)
                    sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        int res = 0;        
        for(int i : sell) res = max(res, i);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{3,2,6,5,0,3};
    s.maxProfit(2, a);
}