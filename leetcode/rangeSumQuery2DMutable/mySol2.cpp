#include "header.h"

class NumMatrix {
private:
    int m = 0, n = 0;
    vector<vector<int>> bit;
    vector<vector<int>> mx;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return;
        m = matrix.size(), n = matrix[0].size();
        bit = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        mx = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - mx[row][col];
        mx[row][col] = val;
        for(int i = row + 1; i <= m; i += i & -i) {
            for(int j = col + 1; j <= n; j += j & -j) {
                bit[i][j] += diff;
            }
        }
    }

    int sum(int row, int col) {
        int res = 0;
        for(int i = row; i > 0; i -= i & -i) {
            for(int j = col; j > 0; j -= j & -j) {
                res += bit[i][j];
            }
        }
        return res;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) - sum(row1, col2 + 1) - sum(row2 + 1, col1) + sum(row1, col1);
    }
};

int main()
{
    //Solution s;
}