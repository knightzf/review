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
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        if(n == 0)
        {
            return 0;
        }

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        dp1[0] = -prices[0];

        for(int i = 1; i < n ; ++i)
        {
            dp1[i] = std::max(dp1[i - 1], dp2[i - 1] - prices[i]);
            dp2[i] = std::max(dp2[i - 1], dp1[i - 1] + prices[i]);
        }

        /*for(auto i : dp1)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        for(auto i : dp2)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        return dp2[n - 1];
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 4, 3, 2, 5, 7};
    s.maxProfit(a);
}
