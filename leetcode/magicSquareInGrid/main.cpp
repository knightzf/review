#include "header.h"

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        for(int i = 0; i <= n - 3; ++i)
        {
            for(int j = 0; j <= n - 3; ++j)
            {
                if(grid[i][j] >= 1 && grid[i][j] <= 9)
                {
                    if(valid(grid, i, j)) ++res;
                }
            }
        }
        return res;
    }

    bool valid(vector<vector<int>>& grid, int a, int b)
    {
        vector<bool> v(10, false);
        for(int i = a; i < a + 3; ++i)
        {
            for(int j = b; j < b + 3; ++j)
            {
                if(grid[i][j] < 1 || grid[i][j] > 9 || v[grid[i][j]])
                    return false;
                v[grid[i][j]] = true;
            }
        }

        int sum = grid[a][b] + grid[a][b + 1] + grid[a][b + 2];
        for(int i = 1; i < 3; ++i)
            if(sum != grid[a + i][b] + grid[a + i][b + 1] + grid[a + i][b + 2]) return false;
        for(int i = 0; i < 3; ++i)
            if(sum != grid[a][b + i] + grid[a + 1][b + i] + grid[a + 2][b + i]) return false;
        if(sum != grid[a][b] + grid[a + 1][b + 1] + grid[a + 2][b + 2]) return false;
        if(sum != grid[a + 2][b] + grid[a + 1][b + 1] + grid[a][b + 2]) return false;
        return true;
    }
};

int main()
{
    Solution s;
}
