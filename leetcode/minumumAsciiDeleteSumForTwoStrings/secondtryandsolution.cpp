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
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        auto count = [](const std::string str) {
            int sum = 0;
            for(char c : str)
            {
                sum += c;
            }

            return sum;
        };

        for(int i = 1; i < m + 1; ++i)
        {
            dp[i][0] = count(s1.substr(0, i));
        }

        for(int i = 1; i < n + 1; ++i)
        {
            dp[0][i] = count(s2.substr(0, i));
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    //std::cout<<sol.minimumDeleteSum("sea", "eat")<<std::endl;
    std::cout<<sol.minimumDeleteSum("delete", "leet")<<std::endl;
    return 0;
}
