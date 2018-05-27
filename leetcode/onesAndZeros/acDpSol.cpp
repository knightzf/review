#include "header.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int, int>> v;
        for(const auto& s : strs)
        {
            int zeroCnt = 0;
            int oneCnt = 0;
            for(char c : s)
            {
                if(c == '0') ++zeroCnt;
                else ++oneCnt;
            }
            v.push_back(make_pair(zeroCnt, oneCnt));
        }

        int res = 0;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(len + 1, 0)));
        for(int i = 0; i <= m; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                for(int k = 1; k <= len; ++k)
                {
                    dp[i][j][k] = dp[i][j][k - 1];
                    if(i - v[k - 1].first >= 0 && j - v[k - 1].second >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - v[k - 1].first][j - v[k - 1].second][k - 1] + 1);
                        res = max(res, dp[i][j][k]);
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a {"10", "0001", "111001", "1", "0"};
    cout<<s.findMaxForm(a, 5, 3)<<endl;
}
