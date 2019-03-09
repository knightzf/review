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

        function<void(int, int, int)> bfs = [&](int i, int j, int mark)
        {
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int qsize = q.size();
            while(!q.empty())
            {
                for(int h = 0; h < qsize; ++h)
                {
                    int a = q.front().first, b = q.front().second;
                    q.pop();
                    grid[a][b] = mark;
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = a + diff[k];
                        int y = b + diff[k + 1];
                        if(x > 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && grid[x][y] != mark) {
                            q.push(make_pair(x, y));
                        }
                    }
                }
                qsize = q.size();
            }
        };

        for(int i = 0; i < n; ++i)
        {
            if(grid[0][i] == 1)
                bfs(0, i, 2);
        }

        unordered_set<int> good{2};

        function<int(int, int, int)> put = [&](int i, int j, int mark)
        {
            int cnt = 0;
            bool toTop = i == 0;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int qsize = q.size();
            while(!q.empty())
            {
                for(int h = 0; h < qsize; ++h)
                {
                    int a = q.front().first, b = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = a + diff[k];
                        int y = b + diff[k + 1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && grid[x][y] != mark) {
                            if(good.count(grid[x][y])) 
                            {
                                toTop = true;
                                continue;
                            }
                            
                            ++cnt;
                            grid[x][y] = mark;
                            q.push(make_pair(x, y));
                        }
                    }
                }
                qsize = q.size();
            }
            if(toTop) {
                good.insert(mark);
                return cnt;
            }
            return 0;
        };

        vector<int> res;
        int mark = 3;
        for(auto iter = hits.rbegin(); iter != hits.rend(); ++iter)
        {
            int x = (*iter)[0], y = (*iter)[1];
            if(grid[x][y])
            {
                grid[x][y] = mark + 1;
                res.push_back(put(x, y, ++mark));
            }
            else res.push_back(0);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> a{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> b{{0, 2}, {2, 0}, {0, 1}, {1, 2}};
    //vector<vector<int>> a{{1, 0, 0, 0}, {1, 1, 0, 0}};
    //vector<vector<int>> b{{1, 1}, {1, 0}};
    //vector<vector<int>> a{{1, 0, 0, 0}, {1, 1, 1, 0}};
    //vector<vector<int>> b{{1, 0}};
    //vector<vector<int>> a{{1},{1},{1},{1},{1}};
    //vector<vector<int>> b{{3,0},{4,0},{1,0},{2,0},{0,0}};
    //vector<vector<int>> a{{1,0,1},{1,1,1}};
    //vector<vector<int>> b{{0,0},{0,2},{1,1}};
    //vector<vector<int>> a{{0,1,1,1,1},{1,1,1,1,0},{1,1,1,1,0},{0,0,1,1,0},{0,0,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    //vector<vector<int>> b{{6,0},{1,0},{4,3},{1,2},{7,1},{6,3},{5,2},{5,1},{2,4},{4,4},{7,3}};
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