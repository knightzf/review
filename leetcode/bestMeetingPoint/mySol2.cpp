#include "header.h"

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> I, J;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    I.emplace_back(i);
                    J.emplace_back(j);
                }
            }
        }
        sort(J.begin(), J.end());
        return median(I) + median(J);
    }

    int median(vector<int>& v) {
        int t = 0;
        if(v.size() & 1) t = v[v.size() / 2];
        else t = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        int res = 0;
        for_each(v.begin(), v.end(), [&](int a) { res += abs(a - t); });
        return res;
    }
};

int main()
{
    //Solution s;
}