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
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;

        vector<int> currentCost = costs[0];
        for(int i = 1; i < n; ++i)
        {
            vector<int> t(3);
            t[0] = costs[i][0] + std::min(currentCost[1], currentCost[2]);
            t[1] = costs[i][1] + std::min(currentCost[0], currentCost[2]);
            t[2] = costs[i][2] + std::min(currentCost[0], currentCost[1]);
            currentCost = t;
        }

        return std::min(currentCost[0], std::min(currentCost[1], currentCost[2]));
    }
};


int main() {
    Solution s;
}
