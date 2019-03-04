#include "header.h"

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if(n == 1) return 0;
        if(K > n || (n - K) % (K - 1) != 0) return -1;
        
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i)
        {
            sum[i + 1] = sum[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = K; len <= n; /*len += K - 1*/++len)
        {
            for(int i = 0; i + len <= n; ++i)
            {
                int j = i + len - 1;
                if((len - K) % (K - 1) != 0)
                {
                    //dp[i][j] = min(dp[i][j - 1], dp[i + (len - K) % (K - 1)][j]);
                    dp[i][j] = dp[i][j - 1];
                    for(int k = j; k > j - (len - K) % (K - 1); --k)
                    {
                        for(int m = k - K + 1; m > i; m -= K - 1)
                        {
                            dp[i][j] = min(dp[i][j], dp[i][m - 1] + dp[m][k]);                            
                        }
                    }
                    continue;
                }
                
                int total = sum[j + 1] - sum[i];
                if(len == K) dp[i][j] = total;
                else
                {
                    dp[i][j] = dp[i][j - K + 1] + total;
                    for(int k = j; k > j - K + 1; --k)
                    {
                        for(int m = k - K + 1; m > i; m -= K - 1)
                        {
                            dp[i][j] = min(dp[i][j], dp[i][m - 1] + dp[m][k] + total);                            
                        }
                    }
                }
            }
        }

        for(auto& i : dp)
        {
            for(int j : i) cout<<setw(2)<<j<<" ";
            cout<<endl;
        }

        return dp[0][n - 1];
    }
};


int main()
{
    Solution s;
    //vector<int> a{95,54,31,48,44,96,99,20,51,54,18,85,25,84,91,48,40,72,22};
    //vector<int> a{4, 6, 4, 7, 5};
    //vector<int> a{3,2,4,1};
    //vector<int> a{9,8,3,2,9,4};
    //cout<<s.mergeStones(a,2)<<endl;
    //vector<int> a{1, 4, 3, 5, 1, 2, 6};
    //vector<int> a{7,7,8,6,5,6,6};
    vector<int> a{4,2,4,6,4,6,9,9,5};
    cout<<s.mergeStones(a,3)<<endl;
}
