#include "header.h"

class Solution {
private:
    int m;
    int n;
    map<vector<int>, int> cache;
    int res;
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) return false;
        m = maze.size();
        n = maze[0].size();
        cache.clear();
        res = INT_MAX;
        dfs(maze, start, destination, 0);
        return res == INT_MAX ? -1 : res;
    }

    void dfs(vector<vector<int>>& maze, const vector<int>& start, const vector<int>& destination, int steps)
    {
        if(start == destination)
        {
            res = min(res, steps);
            return;
        }

        if(cache.count(start) && cache[start] <= steps) return;
        cache[start] = steps;

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
                dfs(maze, vector<int>{x + 1, y}, destination, steps + start[0] - x - 1);
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
                dfs(maze, vector<int>{x - 1, y}, destination, steps + x - 1 - start[0]);
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
                dfs(maze, vector<int>{x, y + 1}, destination, steps + start[1] - y - 1);
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
                dfs(maze, vector<int>{x, y - 1}, destination, steps + y - 1 - start[1]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> b{0, 4};
    vector<int> c{4, 4};
    cout<<s.shortestDistance(a, b, c)<<endl;
}
