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
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;

        std::vector<std::pair<int, int>> directions{{0, 1},{1, 0},{0, -1},{-1, 0}};
        int count = 0;

        std::vector<int> dp(m * n, -1);

        for(const auto& p : positions)
        {
            int idx = n * p.first + p.second;
            dp[idx] = idx;
            ++count;

            for(const auto& dir : directions)
            {
                int x = p.first + dir.first;
                int y = p.second + dir.second;

                if(x < 0 || y < 0 || x >= m || y >= n || dp[x * n + y] == -1) continue;
                int rootOfNeighbor = findRoot(dp, n * x + y);

                if(idx != rootOfNeighbor)
                {
                    dp[idx] = rootOfNeighbor;
                    idx = rootOfNeighbor;
                    --count;
                }
            }

            res.push_back(count);
        }

        return res;
    }

    int findRoot(const vector<int>& dp, int idx)
    {
        while(idx != dp[idx]) idx = dp[idx];
        return idx;
    }
};

int main() {
    Solution s;
}
