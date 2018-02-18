#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;

        vector<int> buy(n, 0);
        vector<int> sell(n, 0);

        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = -prices[1];
        sell[1] = max(0, buy[0] + prices[1]);

        int res = std::max(sell[0], sell[1]);

        for(int i = 2; i < n; ++i)
        {
            //std::cout<<i<<std::endl;
            int t = INT_MIN;
            for(int j = 0; j < i - 1; ++j)
            {
                t = std::max(t, -prices[i] + sell[j]);
            }
            buy[i] = t;

            for(int j = 0; j < i; ++j)
            {
                sell[i] = std::max(sell[i], prices[i] + buy[j]);
            }

            res = std::max(res, sell[i]);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2, 3, 0, 2};
    std::cout<<s.maxProfit(a)<<std::endl;
}
