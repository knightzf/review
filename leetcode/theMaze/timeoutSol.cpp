#include "header.h"

class Solution {
private:
    int m;
    int n;
    set<vector<vector<int>>> cache;
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) return false;
        m = maze.size();
        n = maze[0].size();
        cache.clear();
        maze[start[0]][start[1]] = 5;
        return dfs(maze, start, destination);
    }

    bool dfs(vector<vector<int>>& maze, const vector<int>& start, const vector<int>& destination)
    {
        if(start == destination) return true;

        if(cache.count(maze)) return false;
        cache.insert(maze);

        int x = start[0];
        int y = start[1];

        if(x > 0 && maze[x - 1][y] != 1)
        {
            while(x >= 0 && maze[x][y] != 1)
            {
                --x;
            }

            if(x + 1 < start[0])
            {
                maze[x + 1][y] = 5;
                maze[start[0]][y] = 0;
                if(dfs(maze, vector<int>{x + 1, y}, destination)) return true;
                maze[x + 1][y] = 0;
                maze[start[0]][y] = 5;
            }
        }

        x = start[0];
        y = start[1];
        if(x < m - 1 && maze[x + 1][y] != 1)
        {
            while(x < m && maze[x][y] != 1)
            {
                ++x;
            }

            if(x - 1 > start[0])
            {
                maze[x - 1][y] = 5;
                maze[start[0]][y] = 0;
                if(dfs(maze, vector<int>{x - 1, y}, destination)) return true;
                maze[x - 1][y] = 0;
                maze[start[0]][y] = 5;
            }
        }

        x = start[0];
        y = start[1];
        if(y > 0 && maze[x][y - 1] != 1)
        {
            while(y >= 0 && maze[x][y] != 1)
            {
                --y;
            }

            if(y + 1 < start[1])
            {
                maze[x][y + 1] = 5;
                maze[x][start[1]] = 0;
                if(dfs(maze, vector<int>{x, y + 1}, destination)) return true;
                maze[x][y + 1] = 0;
                maze[x][start[1]] = 5;
            }
        }

        x = start[0];
        y = start[1];
        if(y < n - 1 && maze[x][y + 1] != 1)
        {
            while(y < n && maze[x][y] != 1)
            {
                ++y;
            }

            if(y - 1 > start[1])
            {
                maze[x][y - 1] = 5;
                maze[x][start[1]] = 0;
                if(dfs(maze, vector<int>{x, y - 1}, destination)) return true;
                maze[x][y - 1] = 0;
                maze[x][start[1]] = 5;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> b{0, 4};
    vector<int> c{4, 4};
    cout<<s.hasPath(a, b, c)<<endl;
}
