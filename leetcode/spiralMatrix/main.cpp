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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> result;

        int row = matrix.size();
        int col = 0;
        if(row > 0)
        {
            col = matrix[0].size();
        }

        int x = 0;
        int y = 0;

        while(true)
        {

            if(row <= 0 || col <= 0)
            {
                break;
            }

            int x1 = x;
            int y1 = y;

            int x2 = x;
            int y2 = y + col - 1;

            int x3 = x + row - 1;
            int y3 = y + col - 1;

            int x4 = x + row - 1;
            int y4 = y;

            for(int i = y1; i < y2 + 1; ++i)
            {
                result.push_back(matrix[x1][i]);
            }

            for(int i = x2 + 1; i < x3 + 1; ++i)
            {
                result.push_back(matrix[i][y3]);
            }

            if(x3 != x1)
            {
                for(int i = y3 - 1; i >= y4; --i)
                {
                    result.push_back(matrix[x3][i]);
                }
            }

            if(y4 != y2)
            {
               for(int i = x4 - 1; i > x1; --i)
                {
                    result.push_back(matrix[i][y4]);
                }
            }

            row -= 2;
            col -= 2;

            ++x;
            ++y;
        }

        return result;
    }
};

int main()
{
    Solution sol;

    /*std::vector<std::vector<int>> a{std::vector<int>{1, 2, 3},
                                    std::vector<int>{4, 5, 6},
                                    std::vector<int>{7, 8, 9}};*/

    std::vector<std::vector<int>> a{std::vector<int>{6, 9, 7}};

    const auto& b = sol.spiralOrder(a);
    for(auto i : b)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
