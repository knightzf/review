#include "header.h"

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res{{r0, c0}};
        static vector<pair<int, int>> diff{
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        for(int cnt = 1, i = r0, j = c0, step = 1, t = 0, dir = 0;
            cnt < R * C; dir = (dir + 1) % 4, ++t, step += !(t & 1) ? 1 : 0) {
            for(int k = 0; k < step; ++k) {
                i += diff[dir].first, j += diff[dir].second;
                if(i >= 0 && i < R && j >= 0 && j < C) {
                    res.emplace_back(vector<int>{i, j});
                    ++cnt;
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