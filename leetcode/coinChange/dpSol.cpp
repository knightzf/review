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
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 || coins.empty()) return 0;
        std::sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < amount + 1; ++i)
        {
            if(i >= coins[0])
            {
                for(int j = 0; j < coins.size(); ++j)
                {
                    if(i >= coins[j])
                    {
                        dp[i] = min(dp[i], dp[i - coins[j]] != INT_MAX ? 1 + dp[i - coins[j]] : INT_MAX);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution s;
    //vector<int> a{1, 2, 5};
    //std::cout<<s.coinChange(a, 11)<<std::endl;
    //vector<int> a{2};
    //std::cout<<s.coinChange(a, 3)<<std::endl;
    vector<int> a{186, 419, 83, 408};
    std::cout<<s.coinChange(a, 6249)<<std::endl;
}
