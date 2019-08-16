#include "header.h"

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        unordered_map<int, unordered_map<int, int>> mm;
        auto dis = [&](int i, int j) {
            return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
        };

        function<int(int, int)> dfs = [&](int idx, int visited) {
            if(idx == m) return 0;
            if(mm.count(idx) && mm[idx].count(visited)) return mm[idx][visited];
            int res = INT_MAX;
            for(int i = 0; i < n; ++i) {
                if((visited & (1 << i)) == 0) {
                    visited |= 1 << i;
                    res = min(res, dis(idx, i) + dfs(idx + 1, visited));
                    visited ^= 1 << i;
                }
            }
            mm[idx][visited] = res;
            return res;
        };
        return dfs(0, 0);
    }
};

int main()
{
    Solution s;
}