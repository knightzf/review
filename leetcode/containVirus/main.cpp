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

struct Group
{
    Group() = default;

    std::set<std::pair<int, int>> members;
    std::set<std::pair<int, int>> possibles;

    void combineGroup(Group* group, vector<vector<Group*>>& grid)
    {
        members.insert(group->members.begin(), group->members.end());
        possibles.insert(group->possibles.begin(), group->possibles.end());

        for(const auto& item : group->members)
        {
            grid[item.first][item.second] = this;
        }
    }

    void addMember(int i, int j, const vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        members.insert(std::make_pair(i, j));

        //std::cout<<"add "<<i<<" "<<j<<std::endl;

        if(i > 0 && grid[i - 1][j] == 0)
        {
            //std::cout<<"aa"<<std::endl;
            possibles.insert(std::make_pair(i - 1, j));
        }

        if(j > 0 && grid[i][j - 1] == 0)
        {
            //std::cout<<"bb"<<std::endl;
            possibles.insert(std::make_pair(i, j - 1));
        }

        if(i < m - 1 && grid[i + 1][j] == 0)
        {
            //std::cout<<"cc"<<std::endl;
            possibles.insert(std::make_pair(i + 1, j));
        }

        if(j < n - 1 && grid[i][j + 1] == 0)
        {
            //std::cout<<"dd"<<std::endl;
            possibles.insert(std::make_pair(i, j + 1));
        }
    }

    int buildWalls(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(const auto& item: members)
        {
            int i = item.first;
            int j = item.second;

            grid[i][j] = -1;

            //std::cout<<i<<" "<<j<<std::endl;

            if(i > 0 && grid[i - 1][j] == 0)
            {
                //std::cout<<"a"<<std::endl;
                ++count;
            }

            if(i < m - 1 && grid[i + 1][j] == 0)
            {
                //std::cout<<"b"<<std::endl;
                ++count;
            }

            if(j > 0 && grid[i][j - 1] == 0)
            {
                //std::cout<<"c"<<std::endl;
                ++count;
            }

            if(j < n - 1 && grid[i][j + 1] == 0)
            {
                //std::cout<<"d"<<std::endl;
                ++count;
            }
        }

        return count;
    }
};

class Solution {
public:
    int containVirus(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int walls = 0;
        int count = 0;
        while(true)
        {
            ++count;
            //std::cout<<"before"<<std::endl;
            Group* largest = getLargestGroup(grid);
            //std::cout<<"after"<<std::endl;
            if(!largest)
            {
                break;
            }
            walls += largest->buildWalls(grid);
            spread(grid);

            /*for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    std::cout<<grid[i][j]<<" ";
                }
                std::cout<<std::endl;
            }

            std::cout<<"walls "<<walls<<std::endl;*/
            //if(count == 2) break;
        }

        return walls;
    }

    void spread(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> newGrid(grid);

        /*std::cout<<"before spread"<<std::endl;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout<<grid[i][j]<<" ";
            }
            std::cout<<std::endl;
        }*/

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    //std::cout<<i <<" "<<j<<std::endl;
                    if(i > 0 && grid[i - 1][j] == 0)
                    {
                        newGrid[i - 1][j] = 1;
                    }

                    if(i < m - 1 && grid[i + 1][j] == 0)
                    {
                        newGrid[i + 1][j] = 1;
                    }

                    if(j > 0 && grid[i][j - 1] == 0)
                    {
                        newGrid[i][j - 1] = 1;
                    }

                    if(j < n - 1 && grid[i][j + 1] == 0)
                    {
                        newGrid[i][j + 1] = 1;
                    }
                }
            }
        }

        grid = newGrid;

        /*for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout<<newGrid[i][j]<<" ";
            }
            std::cout<<std::endl;
        }*/
    }

    Group* getLargestGroup(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<Group*>> newGrid(m, std::vector<Group*>(n, nullptr));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //std::cout<<i<<" "<<j<<" "<<grid[i][j]<<std::endl;
                if(grid[i][j] == 1)
                {
                    int upX = i - 1;
                    int upY = j;

                    int leftX = i;
                    int leftY = j - 1;

                    if(
                       (upX < 0 && leftY < 0) ||
                       (upX < 0 && leftY >=0 && grid[leftX][leftY] != 1) ||
                       (upX >= 0 && leftY < 0 && grid[upX][upY] != 1) ||
                       (upX >=0 && leftY >=0 && grid[leftX][leftY] != 1 && grid[upX][upY] != 1)
                       )
                    {
                        Group* g = new Group();
                        g->addMember(i, j, grid);
                        newGrid[i][j] = g;
                    }
                    else if(upX < 0 && leftY >=0 && grid[leftX][leftY] == 1)
                    {
                        newGrid[i][j] = newGrid[leftX][leftY];
                        newGrid[i][j]->addMember(i, j, grid);
                    }
                    else if(upX >= 0 && leftY < 0 && grid[upX][upY] == 1)
                    {
                        newGrid[i][j] = newGrid[upX][upY];
                        newGrid[i][j]->addMember(i, j, grid);
                    }
                    else if(upX >=0 && leftY >=0)
                    {
                        if(grid[leftX][leftY] == 1 && grid[upX][upY] != 1)
                        {
                            newGrid[i][j] = newGrid[leftX][leftY];
                            newGrid[i][j]->addMember(i, j, grid);
                        }
                        else if(grid[leftX][leftY] != 1 && grid[upX][upY] == 1)
                        {
                            newGrid[i][j] = newGrid[upX][upY];
                            newGrid[i][j]->addMember(i, j, grid);
                        }
                        else
                        {
                            if(newGrid[leftX][leftY] == newGrid[upX][upY])
                            {
                                newGrid[i][j] = newGrid[leftX][leftY];
                                newGrid[i][j]->addMember(i, j, grid);
                            }
                            else
                            {
                                newGrid[upX][upY]->combineGroup(newGrid[leftX][leftY], newGrid);
                                newGrid[i][j] = newGrid[upX][upY];
                                newGrid[i][j]->addMember(i, j, grid);
                            }
                        }
                    }
                }
            }
        }

        /*for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(newGrid[i][j])
                {
                    std::cout<<newGrid[i][j]<<" ";
                }
                else
                {
                    std::cout<<"      0 ";
                }
            }
            std::cout<<std::endl;
        }*/

        Group* r = nullptr;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(newGrid[i][j])
                {
                    if(r == nullptr || r->possibles.size() < newGrid[i][j]->possibles.size())
                    {
                        //std::cout<<"check "<<newGrid[i][j]<<" "<<newGrid[i][j]->possibles.size()<<std::endl;
                        r = newGrid[i][j];
                    }
                }
            }
        }

        //std::cout<<"r "<<r<<std::endl;
        return r;
    }
};

int main()
{
    Solution s;
    /*std::vector<std::vector<int>> a{{0,1,0,0,0,0,0,1},
     {0,1,0,0,0,0,0,1},
     {0,0,0,0,0,0,0,1},
     {0,0,0,0,0,0,0,0}};*/
    //std::vector<std::vector<int>> a{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    //std::vector<std::vector<int>> a{{1,1,1,0,0,0,0,0,0},{1,0,1,0,1,1,1,1,1},{1,1,1,0,0,0,0,0,0}};
    std::vector<std::vector<int>> a{{0,1,0,0,0,0,0,1},
     {0,1,0,1,0,0,0,1},
     {0,0,0,0,0,0,0,1}};
    std::cout<<s.containVirus(a)<<std::endl;

}
