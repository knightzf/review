#include "header.h"

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        auto bfs = [&](int x, int y)
        {
            int steps = 1;
            queue<pair<int, int>> q;
            q.push(make_pair(x, y));
            int qsize = q.size();
            static vector<int> diff{-1, 0, 1, 0, -1};
            while(!q.empty()) {
                for(int t = 0; t < qsize; ++t) {
                    const auto& p = q.front();
                    for(int k = 0; k < 4; ++k) {
                        int i = p.first + diff[k], j = p.second + diff[k + 1];
                        if(i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] > 0 && rooms[i][j] > steps) {
                            rooms[i][j] = steps;
                            q.push(make_pair(i, j));
                        }
                    }
                    q.pop();
                }
                qsize = q.size();
                ++steps;
            }
        };

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rooms[i][j] == 0) {
                    bfs(i, j);
                }
            }
        }
    }
};

int main()
{
    Solution s;
}