#include "header.h"

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();        
        const static vector<int> diff{-1, 0, 1, 0, -1};
        
        for(const auto& p : hits)
        {
            if(grid[p[0]][p[1]]) grid[p[0]][p[1]] = -1;
        }

        function<void(int, int, int)> dfs = [&](int i, int j, int mark)
        {
            grid[i][j] = mark;
            for(int k = 0; k < 4; ++k)
            {
                int x = i + diff[k];
                int y = j + diff[k + 1];
                if(x > 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && grid[x][y] != mark) {
                    dfs(x, y, mark);
                }
            }
        };

        for(int i = 0; i < n; ++i)
        {
            if(grid[0][i] == 1)
                dfs(0, i, 2);
        }

        unordered_set<int> good{2};

        function<bool(int, int, int, int&)> put = [&](int i, int j, int mark, int& cnt)
        {            
            bool res = false;
            if(i == 0) {
                res = true;
            }

            for(int k = 0; k < 4; ++k)
            {
                int x = i + diff[k];
                int y = j + diff[k + 1];
                if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && grid[x][y] != mark) {
                    if(x == 0 || good.count(grid[x][y])) 
                    {
                        res = true;
                        continue;
                    }
                    
                    ++cnt;
                    grid[x][y] = mark;
                    res |= put(x, y, mark, cnt);
                }
            }
            return res;            
        };

        vector<int> res;
        int mark = 3;
        for(auto iter = hits.rbegin(); iter != hits.rend(); ++iter)
        {
            int x = (*iter)[0], y = (*iter)[1];
            if(grid[x][y])
            {
                grid[x][y] = mark + 1;
                int cnt = 0;
                if(put(x, y, ++mark, cnt)) {
                    good.insert(mark);
                    res.push_back(cnt);
                    continue;
                }
            }            
            res.push_back(0);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


int main()
{
    Solution s;
    //vector<vector<int>> a{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    //vector<vector<int>> b{{0, 2}, {2, 0}, {0, 1}, {1, 2}};
    //vector<vector<int>> a{{1, 0, 0, 0}, {1, 1, 0, 0}};
    //vector<vector<int>> b{{1, 1}, {1, 0}};
    //vector<vector<int>> a{{1, 0, 0, 0}, {1, 1, 0, 0}};
    //vector<vector<int>> b{{1, 1}, {1, 0}};
    //vector<vector<int>> a{{1, 0, 0, 0}, {1, 1, 1, 0}};
    //vector<vector<int>> b{{1, 0}};
    //vector<vector<int>> a{{1},{1},{1},{1},{1}};
    //vector<vector<int>> b{{3,0},{4,0},{1,0},{2,0},{0,0}};
    //vector<vector<int>> a{{1,0,1},{1,1,1}};
    //vector<vector<int>> b{{0,0},{0,2},{1,1}};
    vector<vector<int>> a{{0,1,1,1,1},{1,1,1,1,0},{1,1,1,1,0},{0,0,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    //vector<vector<int>> b{{6,0},{1,0},{4,3},{1,2},{7,1},{6,3},{5,2},{5,1},{2,4},{4,4},{7,3}};
    vector<vector<int>> b{{1,0},{4,3},{1,2},{5,2},{8,0}};
    /*vector<vector<int>> a{{0,1,1,1,1,1},
                        {1,1,1,1,1,1},
                        {0,0,1,0,0,0},
                        {0,0,0,0,0,0},
                        {0,0,0,0,0,0}};
    vector<vector<int>> b{{1,3},{0,3},{1,1}};*/
    /*vector<vector<int>> a{{0,1,1,1,1,1,1,1,1},
                        {1,1,1,1,1,1,1,1,1},
                        {0,0,0,1,0,0,1,1,1},
                        {0,0,1,1,0,1,1,1,0},
                        {0,0,0,0,0,1,1,1,1},
                        {0,0,0,0,0,0,0,1,0}};
    vector<vector<int>> b{{1,8}};*/

    const auto& r = s.hitBricks(a, b);
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}