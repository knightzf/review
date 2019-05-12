#include "header.h"

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push(make_pair(r0, c0));
        int c = grid[r0][c0];
        visited[r0][c0] = true;
        vector<pair<int, int>> v;
        static vector<int> diff{-1, 0, 1, 0, -1};
        while(!q.empty())
        {
            const auto& p = q.front();

            if(p.first == 0 || p.first == m - 1 || p.second == 0 || p.second == n - 1){
                v.emplace_back(p);
            }

            for(int k = 0; k < 4; ++k)
            {
                int i = p.first + diff[k];
                int j = p.second + diff[k + 1];

                if(i >= 0 && i < m && j >= 0 && j < n && !visited[i][j])
                {
                    auto t = make_pair(i, j);
                    if(grid[i][j] == c)
                    {
                        visited[i][j] = true;
                        q.push(t);
                    }
                    else v.emplace_back(p);
                }
            }
            
            q.pop();
        }

        for(const auto& p : v) grid[p.first][p.second] = color;
        return grid;
    }
};

int main()
{
    Solution s;
}
