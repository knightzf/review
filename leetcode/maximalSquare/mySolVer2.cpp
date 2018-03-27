#include "header.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '0') matrix[i][j] = 0;
                else
                    matrix[i][j] = (i > 0 ? matrix[i - 1][j] : 0) + 1;

                if(matrix[i][j] > 0 && matrix[i][j] > maxLen)
                {
                    int k = j;
                    int t = matrix[i][j];
                    while(k >= 0 && matrix[i][k] != 0)
                    {
                        if(min(t, (int)matrix[i][k]) >= j - k)
                        {
                            t = min(t, (int)matrix[i][k]);
                            --k;
                        }
                        else
                            break;
                    }
                    maxLen = max(maxLen, min(t, j - k));
                }
            }
        }
        return maxLen * maxLen;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    std::cout<<s.maximalSquare(matrix)<<std::endl;;
}
