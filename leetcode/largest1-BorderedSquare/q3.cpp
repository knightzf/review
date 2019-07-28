#include "header.h"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> ul(m, vector<pair<int, int>>(n, {0, 0}));
        auto br = ul;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    ul[i][j] = {1, 1};
                    if(i > 0) ul[i][j].first += ul[i - 1][j].first;
                    if(j > 0) ul[i][j].second += ul[i][j - 1].second;
                }
            }
        }
        int res = 0;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(grid[i][j]) {
                    br[i][j] = {1, 1};
                    if(i < m - 1) br[i][j].first += br[i + 1][j].first;
                    if(j < n - 1) br[i][j].second += br[i][j + 1].second;
                    for(int k = min(br[i][j].first, br[i][j].second); k > res; --k) {
                        if(i + k - 1 < m && j + k - 1 < n &&
                           min(ul[i + k - 1][j + k - 1].first, ul[i + k - 1][j + k - 1].second) >= k) {
                            res = k;
                            break;
                        }
                    }
                }
            }
        }
        return res * res;
    }
};

int main()
{
    Solution s;
}

