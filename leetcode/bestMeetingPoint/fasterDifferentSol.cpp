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
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;

        std::multiset<int> xm;
        std::multiset<int> ym;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    xm.insert(i);
                    ym.insert(j);
                }
            }
        }

        std::vector<int> xv(xm.begin(), xm.end());
        std::vector<int> yv(ym.begin(), ym.end());

        int minX = INT_MAX;
        int x = (xv[0] + xv.back()) / 2;
        while(x <= xv.back())
        {
            int s = 0;
            for(auto t : xv)
            {
                s += std::abs(t - x);
            }

            if(s < minX)
            {
                minX = s;
                ++x;
                continue;
            }

            break;
        }

        x = (xv[0] + xv.back()) / 2 - 1;
        while(x >= xv[0])
        {
            int s = 0;
            for(auto t : xv)
            {
                s += std::abs(t - x);
            }

            if(s < minX)
            {
                minX = s;
                --x;
                continue;
            }

            break;
        }

        int minY = INT_MAX;
        int y = (yv[0] + yv.back()) / 2;
        while(y <= yv.back())
        {
            int s = 0;
            for(auto t : yv)
            {
                s += std::abs(t - y);
            }

            if(s < minY)
            {
                minY = s;
                ++y;
                continue;
            }

            break;
        }

        y = (yv[0] + yv.back()) / 2 - 1;
        while(y >= yv[0])
        {
            int s = 0;
            for(auto t : yv)
            {
                s += std::abs(t - y);
            }

            if(s < minY)
            {
                minY = s;
                --y;
                continue;
            }

            break;
        }

        return minX + minY;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    std::cout<<s.minTotalDistance(a)<<std::endl;

}
