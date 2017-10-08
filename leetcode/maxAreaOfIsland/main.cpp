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

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size();
        if(m == 0)
        {
            return 0;
        }

        int n = grid[0].size();
        if(n == 0)
        {
            return 0;
        }

        int result = 0;

        vector<std::vector<std::set<std::pair<int,int>>*>> dp(
            m,
            std::vector<std::set<std::pair<int,int>>*>(n, nullptr));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    if(i == 0 && j == 0)
                    {
                        std::set<std::pair<int,int>>* t = new std::set<std::pair<int,int>>();
                        t->insert(std::make_pair(i, j));
                        dp[i][j] = t;
                    }
                    else if(i > 0 && j == 0)
                    {
                        if(dp[i - 1][j])
                        {
                            dp[i - 1][j]->insert(std::make_pair(i, j));
                            dp[i][j] = dp[i - 1][j];
                        }
                        else
                        {
                            std::set<std::pair<int,int>>* t = new std::set<std::pair<int,int>>();
                            t->insert(std::make_pair(i, j));
                            dp[i][j] = t;
                        }
                    }
                    else if(i == 0 && j > 0)
                    {
                        if(dp[i][j - 1])
                        {
                            dp[i][j - 1]->insert(std::make_pair(i, j));
                            dp[i][j] = dp[i][j - 1];
                        }
                        else
                        {
                            std::set<std::pair<int,int>>* t = new std::set<std::pair<int,int>>();
                            t->insert(std::make_pair(i, j));
                            dp[i][j] = t;
                        }
                    }
                    else
                    {
                        if(dp[i - 1][j] && dp[i][j - 1] == nullptr)
                        {
                            dp[i - 1][j]->insert(std::make_pair(i, j));
                            dp[i][j] = dp[i - 1][j];
                        }
                        else if(dp[i - 1][j] == nullptr && dp[i][j - 1])
                        {
                            dp[i][j - 1]->insert(std::make_pair(i, j));
                            dp[i][j] = dp[i][j - 1];
                        }
                        else if(dp[i - 1][j] && dp[i][j - 1])
                        {
                            if(dp[i - 1][j] == dp[i][j - 1])
                            {
                                dp[i - 1][j]->insert(std::make_pair(i, j));
                                dp[i][j] = dp[i - 1][j];
                            }
                            else
                            {
                                dp[i - 1][j]->insert(dp[i][j - 1]->begin(), dp[i][j - 1]->end());
                                dp[i - 1][j]->insert(std::make_pair(i, j));
                                dp[i][j] = dp[i - 1][j];

                                for(const auto& item : *dp[i][j - 1])
                                {
                                    dp[item.first][item.second] = dp[i - 1][j];
                                }
                            }
                        }
                        else
                        {
                            std::set<std::pair<int,int>>* t = new std::set<std::pair<int,int>>();
                            t->insert(std::make_pair(i, j));
                            dp[i][j] = t;
                        }
                    }

                    result = std::max(result, int(dp[i][j]->size()));
                }
            }
        }

        /*for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(dp[i][j])
                {
                    std::cout<<dp[i][j]->size()<<" ";
                }
                else
                {
                    std::cout<<"0 ";
                }
            }
            std::cout<<std::endl;
        }*/

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> a{
        std::vector<int>{0, 1},
        std::vector<int>{1, 1},
        std::vector<int>{1, 0}};
    sol.maxAreaOfIsland(a);
    return 0;
}
