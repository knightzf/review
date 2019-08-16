#include "header.h"

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = workers.size(), n = bikes.size();
        vector<vector<pair<int, int>>> dis(2001);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                dis[d].push_back({i, j});
            }
        }
        vector<bool> visitedWorkers(m, false), visitedBikes(n, false);
        vector<int> res(m, -1);
        for(int i = 0; i < 2001; ++i) {
            for(const auto& p : dis[i]) {
                if(!visitedWorkers[p.first] && !visitedBikes[p.second]) {
                    res[p.first] = p.second;
                    visitedWorkers[p.first] = true;
                    visitedBikes[p.second] = true;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}