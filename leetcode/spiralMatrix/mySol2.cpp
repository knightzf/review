#include "header.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while(res.size() < m * n)
        {
            for(int j = left; j < right; ++j)
                res.push_back(matrix[up][j]);
            for(int i = up; i < down; ++i)
                res.push_back(matrix[i][right]);
            if(right > left && down > up) {
                for(int j = right; j > left; --j) res.push_back(matrix[down][j]);
                for(int i = down; i > up; --i) res.push_back(matrix[i][left]);
            }
            else res.push_back(matrix[down][right]);
            
            ++up; --down; ++left; --right;
        }
        return res;
    }
};

int main()
{
    Solution s;
}