#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;

        int i = 0, j = 0;
        while(true)
        {
            if(i >= m || j >=n) return false;

            if(binarySearch(matrix, target, i, j, n, 0)) return true;
            if(binarySearch(matrix, target, j, i, m, 1)) return true;

            ++i; ++j;
        }

        return false;
    }

    bool binarySearch(vector<vector<int>>& matrix, int target, int pivotIndex,
                      int startIdx, int& endIdx, int mode)
    {
        while(true)
        {
            int midIdx = (startIdx + endIdx) / 2;

            if(midIdx == startIdx)
            {
                if(mode == 0)
                {
                    if(matrix[pivotIndex][startIdx] == target) return true;
                }
                else
                {
                    if(matrix[startIdx][pivotIndex] == target) return true;
                }

                break;
            }

            int n;
            if(mode == 0)
            {
                n = matrix[pivotIndex][midIdx];
            }
            else
            {
                n = matrix[midIdx][pivotIndex];
            }

            if(n == target) return true;
            if(n > target)
            {
                endIdx = midIdx;
            }
            else
            {
                startIdx = midIdx;
            }
        }

        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    std::cout<<s.searchMatrix(a, 5)<<std::endl;;
}
