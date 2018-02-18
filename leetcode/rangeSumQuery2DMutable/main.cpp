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

class NumMatrix {
private:
    int m = 0, n = 0;
    vector<vector<int>> bitTrees;
    vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return;

        m = matrix.size();
        n = matrix[0].size();
        bitTrees = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        data = vector<vector<int>>(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if(m == 0 || n == 0) return;

        int diff = val - data[row][col];
        data[row][col] = val;

        for(int i = row + 1; i <= m; i += i & (-i))
        {
            for(int j = col + 1; j <= n; j += j & (-j))
            {
                bitTrees[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(m == 0 || n == 0) return 0;
        return sum(row2+1, col2+1) + sum(row1, col1) - sum(row1, col2+1) - sum(row2+1, col1);
    }

private:
    int sum(int row, int col)
    {
        int sum = 0;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                sum += bitTrees[i][j];
            }
        }
        return sum;
    }
};

int main() {
    //Solution s;

    NumMatrix n({{3,0,1,4,2},{5,6,3,2,1},{1,2,0,1,5},{4,1,0,1,7},{1,0,3,0,5}});
    std::cout<<n.sumRegion(2,1,4,3)<<std::endl;
}
