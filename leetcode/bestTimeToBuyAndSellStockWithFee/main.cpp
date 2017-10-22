#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        if(prices.size() <= 1)
        {
            return 0;
        }

        int n = prices.size();

        std::vector<int> hasStockProfit(n, 0);
        std::vector<int> noStockProfit(n, 0);

        hasStockProfit[0] = -prices[0];

        for(int i = 1; i < n ; ++i)
        {
            hasStockProfit[i] = std::max(hasStockProfit[i - 1], noStockProfit[i - 1] - prices[i]);
            noStockProfit[i] = std::max(noStockProfit[i - 1], hasStockProfit[i - 1] + prices[i] - fee);
        }

        return noStockProfit[n - 1];
    }
};

int main()
{
    Solution sol;
    //std::vector<int> p{4, 5, 2, 4, 3, 3, 1, 2, 5, 4};
    std::vector<int> p{1, 3, 2, 8, 4, 9};
    std::cout<<sol.maxProfit(p, 2)<<std::endl;
    return 0;
}
