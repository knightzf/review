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
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        //dp[i][j] means min distance from word1[0, i) to word2[0, j)
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for(int i = 1; i < m + 1; ++i)
        {
            dp[i][0] = i;
        }

        for(int i = 1; i < n + 1; ++i)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j -1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j -1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        /*for(auto& i : dp)
        {
            for(auto j : i)
            {
                std::cout<<j<<" ";
            }
            std::cout<<std::endl;
        }*/

        return dp[m][n];
    }
};

int main()
{
    Solution sol;
    sol.minDistance("a", "b");
    return 0;
}
