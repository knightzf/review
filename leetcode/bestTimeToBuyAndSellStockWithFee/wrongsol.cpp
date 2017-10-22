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
        if(prices.empty() || prices.size() == 1)
        {
            return 0;
        }

        int n = prices.size();
        int profit = 0;

        int cost = 0;

        std::vector<std::pair<int, int>> v;
         for(int i = 0; i < n; ++i)
        {
            if(i != n - 1 && prices[i] < prices[i + 1] && cost == 0)
            {
                cost = prices[i];
            }

            if(cost != 0 && prices[i] - fee >= cost &&
                (prices[i] > prices[i + 1] || i == n - 1)
               )
            {
                //profit += prices[i] - fee - cost;
                v.push_back(std::make_pair(cost, prices[i]));
                cost = 0;
            }
        }

        /*for(auto i : v)
        {
            std::cout<<i.first<<" "<<i.second<<std::endl;
        }*/

        for(int i = 0; i < v.size(); ++i)
        {
            if(i != v.size() - 1)
            {
                if(v[i + 1].second > v[i].second)
                {
                    if(v[i + 1].second - v[i].first - fee >
                       v[i + 1].second - v[i + 1].first + v[i].second - v[i].first - 2 * fee)
                    {
                        v[i + 1].first = v[i].first;
                    }
                    else
                    {
                        profit += v[i].second - v[i].first - fee;
                    }
                }
                else
                {
                    profit += v[i].second - v[i].first - fee;
                }
            }
            else
            {
                profit += v[i].second - v[i].first - fee;
            }
        }

        return profit;
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
