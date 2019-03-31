#include "header.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();

        function<void(int, int)> bfs = [&](int i, int j)
        {
            static vector<int> diff{-1, 0, 1, 0, -1};
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            int qsize = q.size();
            while(!q.empty())
            {
                for(int i = 0; i < qsize; ++i)
                {
                    const auto& p = q.front();
                    A[p.first][p.second] = -1;
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = p.first + diff[k];
                        int y = p.second + diff[k + 1];
                        if(x >= 0 && x < m && y >= 0 && y < n && A[x][y] == 1)
                        {
                            q.push(make_pair(x, y));
                        }
                    }
                    q.pop();
                }
                qsize = q.size();
            }
        };

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == 0 || i == m -1 || j == 0 || j == n - 1)
                {
                    if(A[i][j] == 1)
                    {
                        bfs(i, j);
                    } 
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(A[i][j] == 1) ++res;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
