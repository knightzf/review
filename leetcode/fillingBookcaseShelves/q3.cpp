#include "header.h"

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            int w = books[i][0], h = books[i][1];
            dp[i + 1] = dp[i] + h;
            for(int j = i - 1; j >= 0; --j) {
                if(w + books[j][0] <= shelf_width) {
                    w += books[j][0];
                    h = max(h, books[j][1]);
                    dp[i + 1] = min(dp[i + 1], dp[j] + h);
                } else break;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
}

