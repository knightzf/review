#include "header.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, make_pair(0, 0)));
        vector<vector<int>> dp2(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || matrix[i - 1][j] == '0') dp[i][j].first = 1;
                    else dp[i][j].first = dp[i - 1][j].first + 1;

                    if(j == 0 || matrix[i][j - 1] == '0') dp[i][j].second = 1;
                    else dp[i][j].second = dp[i][j - 1].second + 1;

                    if(i > 0 && j > 0 && dp2[i - 1][j - 1]) {
                        int len = min(dp[i][j].first, dp[i][j].second);
                        if(len > dp2[i - 1][j - 1]) {                            
                            dp2[i][j] = dp2[i - 1][j - 1] + 1;
                        } else {
                            dp2[i][j] = len;
                        }
                    } else {
                        dp2[i][j] = 1;
                    }
                    res = max(res, dp2[i][j]);
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