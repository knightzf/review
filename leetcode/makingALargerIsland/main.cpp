#include "header.h"

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 0 && hasNeighbor(grid, i, j, m, n))
                {
                    int t = findIsland(grid, i, j, m, n);
                    res = max(res, t);
                }
            }
        }
        return res == 0 ? findIsland(grid, 0, 0, m, n) : res;
    }
private:
    bool hasNeighbor(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        static vector<int> diff{-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; ++k)
        {
            int newI = i + diff[k];
            int newJ = j + diff[k + 1];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1) return true;
        }
        return false;
    }

    int findIsland(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        static vector<int> diff{-1, 0, 1, 0, -1};
        vector<vector<int>> visited(m, vector<int>(n, false));
        visited[i][j] = true;
        int cnt = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while(!q.empty())
        {
            const auto& p = q.front();
            for(int k = 0; k < 4; ++k)
            {
                int newI = p.first + diff[k];
                int newJ = p.second + diff[k + 1];
                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && grid[newI][newJ] == 1 &&
                   visited[newI][newJ] == false)
                {
                    ++cnt;
                    visited[newI][newJ] = true;
                    q.push(make_pair(newI, newJ));
                }
            }
            q.pop();
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1, 0}, {1, 0}};
    std::cout<<s.largestIsland(a)<<std::endl;
}
