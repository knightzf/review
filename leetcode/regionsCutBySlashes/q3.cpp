#include "header.h"

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<pair<bool, bool>>> visited(n, vector<pair<bool, bool>>(n, {false, false}));
        int res = 0;

        function<void(int, int, int)> dfs = [&](int i, int j, int mode)
        {
            switch(mode)
            {
                case 0:
                if(visited[i][j].first && visited[i][j].second) return;
                visited[i][j] = {true, true};
                break;
                case 1:
                if(visited[i][j].first) return;
                visited[i][j].first = true;
                break;
                default:
                if(visited[i][j].second) return;
                visited[i][j].second = true;
                break;
            }

            {
                int x = i - 1;
                int y = j;
                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    if(mode == 0 || (grid[i][j] == '/' && mode == 1) || (grid[i][j] == '\\' && mode == 2))
                    {
                        if(grid[x][y] == ' ') dfs(x, y, 0);
                        else if(grid[x][y] == '/') dfs(x, y, 2);
                        else dfs(x, y, 1);
                    }                        
                }
            }

            {
                int x = i;
                int y = j + 1;
                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    if(mode == 0 || mode == 2)
                    {
                        if(grid[x][y] == ' ') dfs(x, y, 0);
                        else dfs(x, y, 1);
                    }
                }
            }

            {
                int x = i + 1;
                int y = j;
                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    if(mode == 0 || (grid[i][j] == '/' && mode == 2) || (grid[i][j] == '\\' && mode == 1))
                    {
                        if(grid[x][y] == ' ') dfs(x, y, 0);
                        else if(grid[x][y] == '/') dfs(x, y, 1);
                        else dfs(x, y, 2);
                    }                        
                }
            }

            {
                int x = i;
                int y = j - 1;
                if(x >= 0 && x < n && y >= 0 && y < n)
                {
                    if(mode == 0 || mode == 1)
                    {
                        if(grid[x][y] == ' ') dfs(x, y, 0);
                        else dfs(x, y, 2);
                    }
                }
            }
        };

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == ' ')
                {
                    if(visited[i][j].first == false) {
                        dfs(i, j, 0);
                        ++res;
                    }     
                }
                else
                {
                    if(visited[i][j].first == false)
                    {
                        dfs(i, j, 1);
                        ++res;
                    }

                    if(visited[i][j].second == false)
                    {
                        dfs(i, j, 2);
                        ++res;
                    }
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

