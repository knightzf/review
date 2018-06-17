#include "header.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty()) return res;

        int m = matrix.size(), n = matrix[0].size();
        bool direction = true;
        int i = 0, j = 0;
        while(true)
        {
            res.push_back(matrix[i][j]);
            if(direction)
            {
                if(i - 1 < 0 || j + 1 >= n)
                {
                    if(i + 1 >= m && j + 1 >= n) break;
                    if(j + 1 < n)
                        ++j;
                    else
                        ++i;
                    direction = !direction;
                }
                else
                {
                    --i;
                    ++j;
                }
            }
            else
            {
                if(i + 1 >= m || j - 1 < 0)
                {
                    if(i + 1 >= m && j + 1 >= n) break;
                    if(i + 1 < m)
                        ++i;
                    else
                        ++j;
                    direction = !direction;
                }
                else
                {
                    ++i;
                    --j;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
