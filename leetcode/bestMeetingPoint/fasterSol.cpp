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

        vector<std::pair<int, int>> homes;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    homes.emplace_back(std::make_pair(i, j));
                }
            }
        }

        int minX = INT_MAX;
        for(int i = 0; i < m; ++i)
        {
            int t = 0;
            for(const auto& p : homes)
            {
                t += std::abs(p.first - i);
            }
            minX = std::min(minX, t);
        }

        int minY = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            int t = 0;
            for(const auto& p : homes)
            {
                t += std::abs(p.second - i);
            }
            minY = std::min(minY, t);
        }

        return minX + minY;
    }
};

int main() {
    Solution s;

}
