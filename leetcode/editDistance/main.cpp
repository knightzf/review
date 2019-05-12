#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j)
        {
            if(i >= m && j >= n) return 0;
            if(i >= m) return n - j;
            if(j >= n) return m - i;
            if(dp[i][j] == -1)
            {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dfs(i + 1, j + 1);
                } else {
                    dp[i][j] = 1 + min(dfs(i + 1, j+ 1), min(dfs(i + 1, j), dfs(i, j + 1)));
                }
            }
            return dp[i][j];
        };

        return res;
    }
};

int main()
{
    Solution s;
    s.minDistance("horse", "ros");
}