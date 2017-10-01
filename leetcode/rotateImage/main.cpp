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
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        int startX = 0;
        int startY = 0;

        int loop = 0;
        int loopLen = n - 2 * loop;

        while(true)
        {
            if(loopLen == 1 || loopLen == 0)
                break;

            for(int i = 0; i < loopLen - 1; ++i)
            {
                int x1 = startX;
                int y1 = startY + i;

                int x2 = x1 + i;
                int y2 = startY + loopLen - 1;

                int x3 = startX + loopLen - 1;
                int y3 = startY + loopLen - 1 - i;

                int x4 = startX + loopLen - 1 - i;
                int y4 = startY;

                int temp = matrix[x4][y4];

                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = matrix[x1][y1];
                matrix[x1][y1] = temp;
            }

            ++startX;
            ++startY;
            ++loop;
            loopLen = n - 2 * loop;
        }
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> a{vector<int>{1, 2, 3, 4},
                        vector<int>{5, 6, 7, 8},
                        vector<int>{9, 10, 11, 12},
                        vector<int>{13, 14, 15, 16}};

    sol.rotate(a);

    for(const auto& i : a)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
