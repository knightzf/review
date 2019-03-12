#include "header.h"

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        int a = -prices[0], b = INT_MIN, c = INT_MIN, d = INT_MIN;
        for(int i = 1; i < n; ++i)
        {
            if(d == INT_MIN)
            {
                if(c != INT_MIN)
                {
                    d = c + prices[i];
                }
            }
            else
            {
                d = max(d, c + prices[i]);
            }

            if(c == INT_MIN)
            {
               if(b != INT_MIN)
               {
                   c = b - prices[i];
               } 
            }
            else
            {
                c = max(c, b - prices[i]);
            }

            if(b == INT_MIN)
            {
                b = a + prices[i];
            }
            else
            {
                b = max(b, a + prices[i]);
            }

            a = max(a, -prices[i]);                        
        }

        return max(0, max(a, max(b, max(c, d))));
    }
};

int main()
{
    Solution s;
    cout<<s.maxProfit(vector<int>{1, 2, 3, 4, 5})<<endl;
}