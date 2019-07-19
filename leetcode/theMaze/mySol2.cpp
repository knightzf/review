#include "header.h"

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        int ex = destination[0], ey = destination[1];
        if(!((ex == 0 || maze[ex - 1][ey] == 1) || (ex == m - 1 || maze[ex + 1][ey] == 1) ||
          (ey == 0 || maze[ex][ey - 1] == 1) || (ey == n - 1 || maze[ex][ey + 1] == 1))) return false;
        function<bool(int, int)> dfs = [&](int x, int y) {
            if(x == ex && y == ey) return true;
            maze[x][y] = 2;
            int i = x; while(i >= 0 && maze[i][y] != 1) --i;
            if(i != x && maze[i][y] != 2 && dfs(i, y)) return true;
            i = x; while(i < m && maze[i][y] != 1) ++i;
            if(i != x && maze[i][y] != 2 && dfs(i, y)) return true;
            i = y; while(i >= 0 && maze[x][i] != 1) --i;
            if(i != y && maze[x][i] != 2 && dfs(x, i)) return true;
            i = y; while(i < n && maze[x][i] != 1) ++i;
            if(i != y && maze[x][i] != 2 && dfs(x, i)) return true;
            return false;
        };
        return dfs(start[0], start[1]);
    }
};

int main()
{
    //Solution s;
}