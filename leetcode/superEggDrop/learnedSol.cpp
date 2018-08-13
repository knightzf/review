#include "header.h"

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for(int m = 1; m <= N; ++m)
        {
            for(int i = 1; i <= K; ++i)
            {
                dp[i][m] = dp[i - 1][m - 1] + dp[i][m - 1] + 1;
                if(dp[i][m] >= N) return m;
            }
        }
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
