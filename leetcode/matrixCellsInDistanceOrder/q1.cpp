#include "header.h"

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push(vector<int>{r0, c0});
        int qsize = q.size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        visited[r0][c0] = true;
        while(!q.empty())
        {
            for(int i = 0; i < qsize; ++i)
            {
                static vector<int> diff{-1, 0, 1, 0, -1};
                const auto& t = q.front();
                res.emplace_back(t);
                for(int j = 0; j < 4; ++j)
                {
                    int x = t[0] + diff[j];
                    int y = t[1] + diff[j + 1];
                    if(x >= 0 && x < R && y >= 0 && y < C && !visited[x][y]) {                        
                        visited[x][y] = true;
                        q.push(vector<int>{x, y});
                    }
                }
                q.pop();
            }
            qsize = q.size();
        }
        return res;
    }
};

int main()
{
    Solution s;
}
