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
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();

        if(m == 0)
            return false;

        int n = matrix[0].size();

        if(n == 0)
            return false;

        int rowStart = 0;
        int rowEnd = m - 1;
        int rowMid = (rowStart + rowEnd) / 2;

        while(true)
        {
            if(rowMid == rowStart)
            {
                if(rowStart == rowEnd)
                {
                    if(matrix[rowStart][0] <= target && matrix[rowStart][n - 1] >= target)
                    {
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(matrix[rowStart][0] <= target && matrix[rowStart][n - 1] >= target)
                    {
                        break;
                    }
                    else if(matrix[rowEnd][0] <= target && matrix[rowEnd][n - 1] >= target)
                    {
                        rowMid = rowEnd;
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            if(matrix[rowMid][0] > target)
            {
                rowEnd = rowMid;
            }
            else if(matrix[rowMid][0] < target)
            {
                rowStart = rowMid;
            }
            else
            {
                return true;
            }

            rowMid = (rowStart + rowEnd) / 2;
        }

        //std::cout<<rowMid<<std::endl;

        int startIdx = 0;
        int endIdx = n - 1;
        int midIdx = (startIdx + endIdx) / 2;
        while(true)
        {
            if(midIdx == startIdx)
            {
                return matrix[rowMid][startIdx] == target || matrix[rowMid][endIdx] == target;
            }

            if(matrix[rowMid][midIdx] >= target)
            {
                endIdx = midIdx;
            }
            else if(matrix[rowMid][midIdx] <= target)
            {
                startIdx = midIdx;
            }

            midIdx = (startIdx + endIdx) / 2;
        }
    }
};

int main()
{
    Solution sol;
    std::vector<std::vector<int>> a {
        std::vector<int>{1, 3, 5, 7},
        std::vector<int>{10, 11, 16, 20},
        std::vector<int>{23, 30, 34, 50}};
    std::cout<<sol.searchMatrix(a, 3)<<std::endl;
    return 0;
}
