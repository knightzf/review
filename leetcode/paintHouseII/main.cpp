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
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        if(m == 0) return 0;
        int n = costs[0].size();
        if(n == 0) return 0;

        int minIdx = -1;
        int secondIdx = -1;

        for(int i = 0; i < m; ++i)
        {
            int localMin = INT_MAX;
            int localMinIdx = -1;
            int localSecondMin = INT_MAX;
            int localSecondIdx = -1;

            for(int j = 0; j < n; ++j)
            {
                if(minIdx != -1)
                {
                    costs[i][j] += minIdx == j ? costs[i - 1][secondIdx] : costs[i - 1][minIdx];
                }

                if(costs[i][j] < localMin)
                {
                    localSecondMin = localMin;
                    localSecondIdx = localMinIdx;
                    localMin = costs[i][j];
                    localMinIdx = j;
                }
                else if(costs[i][j] < localSecondMin)
                {
                    localSecondMin = costs[i][j];
                    localSecondIdx = j;
                }
            }

            minIdx = localMinIdx;
            secondIdx = localSecondIdx;

            std::cout<<minIdx<<" "<<secondIdx<<std::endl;
        }

        int minCost = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            minCost = std::min(minCost, costs[m - 1][i]);
        }

        return minCost;
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1, 5, 3}, {2, 9, 4}};
    s.minCostII(a);
}
