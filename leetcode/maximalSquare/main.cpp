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
#include <iterator>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;

        vector<vector<std::pair<int,int>>> grid(m, vector<std::pair<int,int>>(n, std::make_pair(0, 0)));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    int leftOneSize = 1;
                    int upOneSize = 1;

                    if(i > 0) leftOneSize += grid[i - 1][j].first;
                    if(j > 0) upOneSize += grid[i][j - 1].second;

                    grid[i][j].first = leftOneSize;
                    grid[i][j].second = upOneSize;
                }
            }
        }

        /*for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                std::cout<<grid[i][j].first <<" "<<grid[i][j].second<<" | ";
            }
            std::cout<<std::endl;
        }*/

        int maxSize = 0;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    int k = 1;
                    while(i + k < m && j + k < n)
                    {
                        if(std::min(grid[i + k][j + k].first, grid[i + k][j + k].second) >= k + 1)
                        {
                            ++k;
                        }
                        else
                        {
                            break;
                        }
                    }

                    maxSize = std::max(maxSize, k);
                }
            }
        }

        return maxSize * maxSize;
    }
};

int main() {
    Solution s;
    /*vector<vector<char>> a{{'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}};*/

    vector<vector<char>> a{{'0','1','1','0','1'},
    {'1','1','0','1','0'},
    {'0','1','1','1','0'},
    {'1','1','1','1','0'},
    {'1','1','1','1','1'},
    {'0','0','0','0','0'}};

    std::cout<<s.maximalSquare(a)<<std::endl;
}
