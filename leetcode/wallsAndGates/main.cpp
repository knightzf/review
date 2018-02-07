#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if(m == 0) return;
        int n = rooms[0].size();
        if(n == 0) return;

        std::set<std::pair<int, int>> s;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(rooms[i][j] == 0)
                {
                    s.emplace(i, j);
                }
            }
        }

        int dis = 0;
        while(!s.empty())
        {
            std::set<std::pair<int, int>> t;
            for(const auto& p : s)
            {
                rooms[p.first][p.second] = dis;
            }

            for(const auto& p : s)
            {
                if(p.first > 0 && rooms[p.first - 1][p.second] == INT_MAX)
                {
                    t.emplace(p.first - 1, p.second);
                }
                if(p.first < m - 1 && rooms[p.first + 1][p.second] == INT_MAX)
                {
                    t.emplace(p.first + 1, p.second);
                }
                if(p.second > 0 && rooms[p.first][p.second - 1] == INT_MAX)
                {
                    t.emplace(p.first, p.second - 1);
                }
                if(p.second < n - 1 && rooms[p.first][p.second + 1] == INT_MAX)
                {
                    t.emplace(p.first, p.second + 1);
                }
            }

            s = t;
            ++dis;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    s.wallsAndGates(a);

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            std::cout<<a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
