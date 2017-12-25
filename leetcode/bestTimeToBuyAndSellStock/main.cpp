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

        int max = 0;

        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(prices[j] - prices[i] > 0)
                {
                    max = std::max(max, prices[j] - prices[i]);
                }
            }
        }

        return max;
    }
};

int main()
{
    Solution s;

}
