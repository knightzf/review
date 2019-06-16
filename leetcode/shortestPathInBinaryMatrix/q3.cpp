#include "header.h"

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;
        deque<pair<int, int>> q;
        q.push_back(make_pair(0, 0));
        grid[0][0] = 2;
        int qsize = q.size();
        int res = 1;
        while(!q.empty()) {
            for(int i = 0; i < qsize; ++i) {
                const auto& p = q.front();
                if(p.first == n - 1 && p.second == n - 1) return res;
                for(int r = p.first - 1; r <= p.first + 1; ++r) {
                    for(int c = p.second - 1; c <= p.second + 1; ++c) {
                        if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0) {
                            grid[r][c] = 2;
                            q.push_back(make_pair(r, c));
                        }
                    }
                }
                q.pop_front();
            }
            ++res;
            qsize = q.size();
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,0,0,0,1},
 {1,0,0,0,0},
 {0,1,0,1,0},
 {0,0,0,1,1},
 {0,0,0,1,0}};
    s.shortestPathBinaryMatrix(a);
}

