#include "header.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        if(q.empty() || q.size() == m * n) return -1;
        int qsize = q.size(), dis = 0;
        static vector<int> diff{-1, 0, 1, 0, -1};
        while(!q.empty()) {
            ++dis;
            for(int i = 0; i < qsize; ++i) {
                int x = q.front()[0], y = q.front()[1];
                for(int k = 0; k < 4; ++k) {
                    int a = x + diff[k], b = y + diff[k + 1];
                    if(a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 0) {
                        grid[a][b] = dis;
                        q.push({a, b});
                    }
                }
                q.pop();
            }
            qsize = q.size();
            if(qsize == 0) --dis;
        }
        return dis;
    }
};

int main()
{
    Solution s;
}

