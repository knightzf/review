#include "header.h"

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sum = m * n - 1;
        int sx, sy, ex, ey;
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == -1) --sum;
                if(grid[i][j] == 1) {sx = i; sy = j;}
                if(grid[i][j] == 2) {ex = i; ey = j; grid[i][j] = 0;}
            }
        }

        function<void(int, int, int)> dfs = [&](int i, int j, int cnt)
        {
            cout<<i<<" "<<j<<" "<<cnt<<endl;
            if(i == ex && j == ey && cnt == sum) 
            {
                ++res; 
                return;
            }

            static vector<int> diff{-1, 0, 1, 0, -1};

            for(int k = 0; k < 4; ++k)
            {
                int x = i + diff[k];
                int y = j + diff[k + 1];

                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0)
                {
                    grid[x][y] = -1;
                    dfs(x, y, cnt + 1);
                    grid[x][y] = 0;
                }
            }
        };

        dfs(sx, sy, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<<s.uniquePathsIII(a)<<endl;
}
