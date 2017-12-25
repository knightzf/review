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
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        if(n == 0)
        {
            return 0;
        }

        int K = k;

        if (k >= n / 2) return quickSolve(prices);

        vector<int> hold(k+1, INT_MIN);
        vector<int> rele(k+1, 0);

        for (int i = 0; i < n; ++i)
        {
            int cur = prices[i];
            //for(int j = k; j > 0; --j)
            for(int j = 1; j < k + 1; ++j)
            {
                rele[j] = max(rele[j], hold[j] + cur);
                hold[j] = max(hold[j], rele[j - 1] - cur);
            }
        }

        return rele[k];
    }

    int quickSolve(vector<int>& prices)
    {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++)
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        return profit;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 5, 4, 3, 5, 8};
    std::cout<<s.maxProfit(2, a)<<std::endl;;
}
