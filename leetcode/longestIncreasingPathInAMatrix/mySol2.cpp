#include "header.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int>> v;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                v.emplace_back(make_pair(i, j));
        sort(v.begin(), v.end(), [&](const auto& a, const auto& b) {
            return matrix[a.first][a.second] < matrix[b.first][b.second];
        });
        vector<vector<int>> count(m, vector<int>(n, 1));
        int res = 0;
        for(const auto& p : v) {
            int i = p.first, j = p.second;
            static vector<int> diff{-1, 0, 1, 0, -1};
            for(int k = 0; k < 4; ++k) {
                int x = i + diff[k], y = j + diff[k + 1];
                if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] > matrix[x][y]) {
                    count[i][j] = max(count[i][j], count[x][y] + 1);
                }
            }
            res = max(res, count[i][j]);
        }
        return res;
    }
};

int main()
{
    Solution s;
}