#include "header.h"

class Solution {
private:
    int m;
    int n;
    set<vector<int>> cache;
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) return false;
        m = maze.size();
        n = maze[0].size();
        cache.clear();
        return dfs(maze, start, destination);
    }

    bool dfs(vector<vector<int>>& maze, const vector<int>& start, const vector<int>& destination)
    {
        if(start == destination) return true;

        if(cache.count(start)) return false;
        cache.insert(start);

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
                if(dfs(maze, vector<int>{x + 1, y}, destination)) return true;
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
                if(dfs(maze, vector<int>{x - 1, y}, destination)) return true;
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
                if(dfs(maze, vector<int>{x, y + 1}, destination)) return true;
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
                if(dfs(maze, vector<int>{x, y - 1}, destination)) return true;
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
