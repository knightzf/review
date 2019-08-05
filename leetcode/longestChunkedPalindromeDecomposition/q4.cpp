#include "header.h"

class Solution {
public:
    int longestDecomposition(string text) {
        unordered_map<int, unordered_map<int, int>> dp;
        function<int(int, int)> dfs = [&](int startIdx, int endIdx) {
            if(startIdx >= endIdx) return 0;
            if(startIdx + 1 == endIdx) return 1;
            if(dp.count(startIdx) && dp[startIdx].count(endIdx)) return dp[startIdx][endIdx];
            dp[startIdx][endIdx] = 1;
            for(int i = startIdx; i < endIdx; ++i) {
                int len = i - startIdx + 1, j = endIdx - len;
                if(i >= j) break;
                if(text.substr(startIdx, len) == text.substr(endIdx - len, len)) {
                    dp[startIdx][endIdx] = max(dp[startIdx][endIdx], dfs(i + 1, endIdx - len) + 2);
                }
            }
            return dp[startIdx][endIdx];
        };
        return dfs(0, text.size());
    }
};

int main()
{
    Solution s;
}
