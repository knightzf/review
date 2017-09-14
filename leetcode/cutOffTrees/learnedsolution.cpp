#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;

struct Position
{
    Position(size_t x_, size_t y_, int v_) :
        x(x_), y(y_), value(v_)
    {

    }
    size_t x;
    size_t y;
    int value;

    bool operator< (const Position& b) const
    {
        return value < b.value;
    }
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest)
    {
        if(forest[0][0] == 0)
            return -1;

        std::set<Position> trees;
        for(size_t i = 0; i < forest.size(); ++i)
        {
            for(size_t j = 0; j < forest[i].size(); ++j)
            {
                if(forest[i][i] > 1)
                {
                    trees.insert(Position(i, j, forest[i][j]));
                }
            }
        }

        int result = 0;
        size_t x = 0; size_t y = 0;
        for(const auto& tree : trees)
        {
            int step = numSteps(x, y, tree.x, tree.y, forest);
            if(step == -1)
            {
                return -1;
            }
            else
            {
                result += step;
                x = tree.x;
                y = tree.y;
                forest[tree.x][tree.y] = 1;
            }
        }

        return result;
    }

    int numSteps(size_t x, size_t y, size_t a, size_t b, const vector<vector<int>>& forest)
    {
        static vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int m = forest.size();
        int n = forest[0].size();

        if(x == a && y == b)
        {
            return 0;
        }

        int steps = 0;

        std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(x, y));
        visited[x][y] = 1;

        while(!q.empty())
        {
            ++steps;

            size_t qsize = q.size();

            while(qsize-- > 0)
            {
                int currX = q.front().first;
                int currY = q.front().second;

                q.pop();

                for(size_t i = 0; i < 4; ++i)
                {
                    int x = currX + dir[i][0];
                    int y = currY + dir[i][1];

                    if(x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && visited[x][y] == 0)
                    {
                        if(x == a && y == b)
                        {
                            return steps;
                        }

                        visited[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    //Solution sol;
    return 0;
}
