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
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(rooms[i][j] == INT_MAX)
                {
                    impl(rooms, m, n, i, j);
                }
            }
        }
    }

    void impl(vector<vector<int>>& rooms, int m, int n, int i, int j)
    {
        static vector<int> diff{1, 0, -1, 0, 1};
        int res = rooms[i][j];
        rooms[i][j] = INT_MIN;
        for(int k = 0; k < 4; ++k)
        {
            int newI = i + diff[k], newJ = j + diff[k + 1];
            if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && rooms[newI][newJ] != -1
               && rooms[newI][newJ] != INT_MIN)
            {
                if(rooms[newI][newJ] == 0)
                {
                    rooms[i][j] = 1;
                    return;
                }
                else
                {
                    impl(rooms, m, n, newI, newJ);
                    if(rooms[newI][newJ] != INT_MAX)
                    res = min(res, 1 + rooms[newI][newJ]);
                }
            }
        }
        rooms[i][j] = res;// == INT_MIN ? INT_MAX : res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    /*vector<vector<int>> a{
        {0, -1, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0},
        {INT_MAX, -1, -1, INT_MAX, -1, -1, INT_MAX}
    };*/
    s.wallsAndGates(a);
    for(const auto& i : a)
    {
        for(int j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
