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

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int n = bits.size();

        if(n == 1 || bits[n - 2] == 0)
        {
            return true;
        }

        if(n == 2)
        {
            return bits[0] == 0;
        }

        std::vector<bool> dp(n - 2, false);
        dp[0] = bits[0] == 0;

        for(int i = 1; i < n - 2; ++i)
        {
            if(i == 1)
            {
                dp[i] = dp[0] ? bits[i] == 0 : true;
            }
            else
            {
                dp[i] = (dp[i - 2] && bits[i - 1] == 1) ||
                        (dp[i - 1] && bits[i] == 0);
            }
        }

        return dp[n - 3] == false;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1, 0, 0};
    std::vector<int> b{1, 1, 1, 0};
    std::cout<<sol.isOneBitCharacter(a)<<std::endl;
    std::cout<<sol.isOneBitCharacter(b)<<std::endl;
}
