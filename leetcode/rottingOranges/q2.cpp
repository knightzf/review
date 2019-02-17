#include "header.h"

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total = 0;
        deque<pair<int, int>> q;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j]) ++total;
                if(grid[i][j] == 2) q.push_back(make_pair(i, j));
            }
        }

        int qsize = q.size();
        int count = 0, minute = 0;
        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                static vector<int> diff{-1, 0, 1, 0, -1};
                int x = q.front().first;
                int y = q.front().second;
                ++count;
                for(int j = 0; j < 4; ++j)
                {
                    int a = x + diff[j];
                    int b = y + diff[j + 1];
                    if(a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1)
                    {
                        grid[a][b] = 2;
                        q.push_back(make_pair(a, b));
                    }
                }
                q.pop_front();
            }

            qsize = q.size();
            if(qsize) ++minute;
        }

        return count == total ? minute : 0;
    }
};

int main()
{
    Solution s;
}
