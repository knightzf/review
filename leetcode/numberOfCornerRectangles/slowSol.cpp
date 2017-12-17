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
    int countCornerRectangles(vector<vector<int>>& grid)
    {
        if(grid.size() == 0 || grid.size() == 1)
        {
            return 0;
        }

        if(grid[0].size() == 0 || grid[0].size() == 1)
        {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

        for(int i = 0; i < m - 1; ++i)
        {
            for(int j = 0; j < n - 1; ++j)
            {
                if(grid[i][j])
                {
                    for(int a = i + 1; a < m; ++a)
                    {
                        for(int b = j + 1; b < n; ++b)
                        {
                            if(grid[a][b])
                            {
                                if(grid[i][b] && grid[a][j])
                                {
                                    ++res;
                                }
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    /*std::vector<std::vector<int>> a{
        {1, 0, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };*/

    std::vector<std::vector<int>> a{
        {1, 1, 1,},
        {1, 1, 1,},
        {1, 1, 1,}
    };

    std::cout<<s.countCornerRectangles(a)<<std::endl;
}
