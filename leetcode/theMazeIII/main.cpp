#include "header.h"

class Solution {
private:
    int m;
    int n;
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& hole) {
        if(maze.empty() || maze[0].empty()) return "impossible";
        m = maze.size();
        n = maze[0].size();

        unordered_map<int, unordered_set<int>> s;

        multimap<int, pair<string, vector<int>>> mp;
        mp.insert(make_pair(0, make_pair("", start)));

        int len = INT_MAX;
        map<int, set<string>> path;

        while(!mp.empty())
        {
            auto iter = mp.begin();
            auto steps = iter->first;
            if(steps > len) break;

            auto currPath = iter->second.first;
            auto p = iter->second.second;
            mp.erase(iter);

            int x = p[0], y = p[1];
            s[x].insert(y);
            if(x > 0 && maze[x - 1][y] == 0)
            {
                while(x >= 0 && maze[x][y] == 0) --x;
                if(hole[1] == y && x + 1 <= hole[0] && p[0] >= hole[0])
                {
                    if(steps + p[0] - hole[0] <= len)
                    {
                        len = steps + p[0] - hole[0];
                        path[len].insert(currPath + "u");
                    }
                }
                else if(s.count(x + 1) == 0 || s[x + 1].count(y) == 0)
                {
                    mp.insert(make_pair(steps + p[0] - x - 1,
                                        make_pair(currPath + "u", vector<int>{x + 1, y})));
                }
            }

            x = p[0]; y = p[1];
            if(x < m - 1 && maze[x + 1][y] == 0)
            {
                while(x < m && maze[x][y] == 0) ++x;
                if(hole[1] == y && x - 1 >= hole[0] && p[0] <= hole[0])
                {
                    if(steps + hole[0] - p[0] <= len)
                    {
                        len = steps + hole[0] - p[0];
                        path[len].insert(currPath + "d");
                    }
                }
                else if(s.count(x - 1) == 0 || s[x - 1].count(y) == 0)
                {
                    mp.insert(make_pair(steps + x - 1 - p[0],
                                        make_pair(currPath + "d", vector<int>{x - 1, y})));
                }
            }

            x = p[0]; y = p[1];
            if(y > 0 && maze[x][y - 1] == 0)
            {
                while(y >= 0 && maze[x][y] == 0) --y;
                if(hole[0] == x && y + 1 <= hole[1] && p[1] >= hole[1])
                {
                    if(steps + p[1] - hole[1] <= len)
                    {
                        len = steps + p[1] - hole[1];
                        path[len].insert(currPath + "l");
                    }
                }
                else if(s[x].count(y + 1) == 0)
                {
                    mp.insert(make_pair(steps + p[1] - y - 1,
                                        make_pair(currPath + "l", vector<int>{x, y + 1})));
                }
            }

            x = p[0]; y = p[1];
            if(y < n - 1 && maze[x][y + 1] == 0)
            {
                while(y < n && maze[x][y] == 0) ++y;
                if(hole[0] == x && y - 1 >= hole[1] && p[1] <= hole[1])
                {
                    if(steps + hole[1] - p[1] <= len)
                    {
                        len = steps + hole[1] - p[1];
                        path[len].insert(currPath + "r");
                    }
                }
                else if(s[x].count(y - 1) == 0)
                {
                    mp.insert(make_pair(steps + y - 1 - p[1],
                                        make_pair(currPath + "r", vector<int>{x, y - 1})));
                }
            }
        }

        if(path.empty()) return "impossible";
        return *(path.begin()->second.begin());
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
    vector<int> b{4, 3};
    vector<int> c{0, 1};
    cout<<s.findShortestWay(a, b, c)<<endl;
}
