#include "header.h"

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        vector<pair<int, int>> v;
        int n = boxes.size();
        for(int i = 0; i < n;)
        {
            int j = i;
            while(j < n && boxes[j] == boxes[i]) ++j;
            v.emplace_back(boxes[i], j - i);
            i = j;
        }

        n = v.size();

        vector<vector<int>> dp(n + 1, vector<int>(n, 0));
        for(int len = 1; len <= n; ++len)
        {
            for(int i = 0; i <= n - len; ++i)
            {
                if(len == 1) dp[len][i] = v[i].second * v[i].second;
                else
                {
                    int j = i + len - 1;
                    int res = 0;//dp[len - 1][i] + dp[1][j];

                    if(v[i].first == v[j].first)
                    {
                        int t = v[i].second;
                        int sum = 0;
                        int prevIdx = i;
                        for(int m = i + 1; m <= j; ++m)
                        {
                            if(v[m].first == v[j].first)
                            {
                                t += v[m].second;
                                sum += dp[m - prevIdx - 1][prevIdx + 1];
                                prevIdx = m;
                            }
                        }
                        sum += t * t;
                        res = max(res, sum);
                    }

                    for(int k = i; k <= j; ++k)
                    {
                        /*if(v[k].first == v[j].first)
                        {
                            res = max(res, dp[k - i][i] + dp[j - k + 1][k]);
                            res = max(res, dp[k - i + 1][i] + dp[j - k][k + 1]);
                        }*/
                        res = max(res, dp[k - i][i] + dp[j - k][k]);
                    }
                    dp[len][i] = res;
                }
            }
        }

        /*for(const auto& i : dp)
        {
            for(auto j : i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        return dp[n][0];
    }
};

int main()
{
    Solution s;
    vector<int> a{1,3,2,2,2,3,4,3,1};
    cout<<s.removeBoxes(a)<<endl;;
}
