#include "header.h"

class Solution {
private:
    int m;
    int n;
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) return false;
        m = maze.size();
        n = maze[0].size();

        unordered_map<int, unordered_set<int>> s;

        multimap<int, vector<int>> mp;
        mp.insert(make_pair(0, start));

        while(!mp.empty())
        {
            auto iter = mp.begin();
            if(iter->second == destination) return iter->first;
            auto steps = iter->first;
            auto p = iter->second;
            mp.erase(iter);

            int x = p[0], y = p[1];
            s[x].insert(y);
            if(x > 0 && maze[x - 1][y] == 0)
            {
                while(x >= 0 && maze[x][y] == 0) --x;
                if(s.count(x + 1) == 0 || s[x + 1].count(y) == 0)
                {
                    mp.insert(make_pair(steps + p[0] - x - 1, vector<int>{x + 1, y}));
                }
            }

            x = p[0]; y = p[1];
            if(x < m - 1 && maze[x + 1][y] == 0)
            {
                while(x < m && maze[x][y] == 0) ++x;
                if(s.count(x - 1) == 0 || s[x - 1].count(y) == 0)
                {
                    mp.insert(make_pair(steps + x - 1 - p[0], vector<int>{x - 1, y}));
                }
            }

            x = p[0]; y = p[1];
            if(y > 0 && maze[x][y - 1] == 0)
            {
                while(y >= 0 && maze[x][y] == 0) --y;
                if(s[x].count(y + 1) == 0)
                {
                    mp.insert(make_pair(steps + p[1] - y - 1, vector<int>{x, y + 1}));
                }
            }

            x = p[0]; y = p[1];
            if(y < n - 1 && maze[x][y + 1] == 0)
            {
                while(y < n && maze[x][y] == 0) ++y;
                if(s[x].count(y - 1) == 0)
                {
                    mp.insert(make_pair(steps + y - 1 - p[1], vector<int>{x, y - 1}));
                }
            }
        }
        return -1;
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
