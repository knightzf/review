#include "header.h"

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= K; ++i)
            dp[i][1] = 1;
        for(int i = 1; i <= N; ++i)
            dp[1][i] = i;
        for(int i = 2; i <= K; ++i)
        {
            for(int j = 2; j <= N; ++j)
            {
                if(i > j)
                {
                    dp[i][j] = dp[j][j];
                }
                else
                {
                    int t = N;
                    for(int k = i/j; k <= j/2; ++k)
                    {
                        t = min(t, 1 + max(dp[i - 1][k], dp[i][j - k - 1]));
                    }
                    dp[i][j] = t;
                }
            }
        }

        /*for(int i = 0; i <= K; ++i)
        {
            for(int j = 0; j <= N; ++j)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
        return dp[K][N];
    }
};

int main()
{
    Solution s;
    cout<<s.superEggDrop(3, 2)<<endl;
    cout<<s.superEggDrop(1, 2)<<endl;
    cout<<s.superEggDrop(2, 6)<<endl;
    cout<<s.superEggDrop(3, 14)<<endl;
    cout<<s.superEggDrop(2, 9)<<endl;
    cout<<s.superEggDrop(6, 10000)<<endl;
    cout<<s.superEggDrop(8, 10000)<<endl;
}
