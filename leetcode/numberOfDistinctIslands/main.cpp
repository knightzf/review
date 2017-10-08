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
    int numDistinctIslands(vector<vector<int>>& grid)
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
                }
            }
        }

        std::map<int, std::set<std::set<std::pair<int,int>>*>> resultMap;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(dp[i][j])
                {
                    if(resultMap.find(dp[i][j]->size()) == resultMap.end())
                    {
                        std::set<std::set<std::pair<int,int>>*> t;
                        t.insert(dp[i][j]);
                        resultMap.insert(std::make_pair(dp[i][j]->size(), t));
                    }
                    else
                    {
                        resultMap[dp[i][j]->size()].insert(dp[i][j]);
                    }
                }
            }
        }

        int result = 0;

        for(auto& item : resultMap)
        {
            std::vector<std::set<std::pair<int, int>>> v;
            std::for_each(item.second.begin(), item.second.end(), [&v](std::set<std::pair<int,int>>* s) {
                            auto& first = *(s->begin());
                            int sx = first.first;
                            int sy = first.second;
                            std::set<std::pair<int,int>> newSet;
                            for(auto& p : *s)
                            {
                                std::pair<int, int> a(p.first - sx, p.second - sy);
                                newSet.insert(a);
                            }
                            v.push_back(newSet);
                          });

            std::sort(v.begin(), v.end(), [](const std::set<std::pair<int, int>>& a,
                                             const std::set<std::pair<int, int>>& b) {
                        return a.begin()->first < b.begin()->first;
                      });

            ++result;

            std::cout<<item.first<<" "<<v.size()<<std::endl;

            for(int i = 1; i < v.size(); ++i)
            {
                int j = i - 1;
                if(v[i] != v[j])
                {
                    ++result;
                }
            }

            /*for(auto& i : v)
            {
                for(auto& j : i)
                {
                    std::cout<<j.first<<" "<<j.second<<", ";
                }

                std::cout<<std::endl;
            }*/
        }

        return result;

    }
};

int main()
{
    Solution sol;
    /*vector<vector<int>> a{
        std::vector<int>{1, 1, 0, 0, 0},
        std::vector<int>{1, 1, 0, 0, 0},
        std::vector<int>{0, 0, 0, 1, 1},
        std::vector<int>{0, 0, 0, 1, 1}
        };*/
    vector<vector<int>> a{
        std::vector<int>{0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0},
        std::vector<int>{0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0},
        std::vector<int>{0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0},
        std::vector<int>{1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1}
        };
    std::cout<<sol.numDistinctIslands(a)<<std::endl;
    return 0;
}
