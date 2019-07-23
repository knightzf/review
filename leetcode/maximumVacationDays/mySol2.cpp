#include "header.h"

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<int> dp(n, -1);
        dp[0] = days[0][0];
        for(int i = 1; i < n; ++i) {
            if(flights[0][i]) dp[i] = days[i][0];
        }

        for(int i = 1; i < k; ++i) {
            vector<int> t(n, -1);
            for(int j = 0; j < n; ++j) {
                for(int l = 0; l < n; ++l) {
                    if(dp[j] != -1) {
                        if(flights[j][l]) t[l] = max(t[l], dp[j] + days[l][i]);
                        else if(j == l) t[l] = max(t[l], dp[l] + days[l][i]);
                    }
                }
            }
            dp = t;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution s;
}