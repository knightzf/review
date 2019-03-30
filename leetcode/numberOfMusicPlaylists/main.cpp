#include "header.h"

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numMusicPlaylists(int N, int L, int K) {
        long res = 1;
        for(int i = 0; i <= K; ++i)
        {
            res *= (N - i);
            res %= mod;
        }

        vector<vector<int>> dp(L + 1, vector<int>(N + 1, 0));

        function<long(int, int)> helper = [&](int len, int missingIds)
        {
            if(dp[len][missingIds] != 0) return (long)dp[len][missingIds];
            //cout<<len<<" "<<missingIds<<endl;
            long t = 1;
            if(missingIds == 0)
            {
                while(len)
                {
                    t *= (N - K);
                    t %= mod;
                    --len;
                }
                return t;
            }

            if(len == missingIds)
            {
                while(len)
                {
                    t *= len;
                    t %= mod;
                    --len;
                }
                return t;
            }

            t = missingIds * helper(len - 1, missingIds - 1);
            t %= mod;
            if(len > missingIds)
            {
                t += (N - K - missingIds) * helper(len - 1, missingIds);
                t %= mod;
            }
            dp[len][missingIds] = t;
            return t;
        };
        //cout<<"test "<<L - K - 1<<" "<<N - K - 1<<endl;
        res *= helper(L - K - 1, N - K - 1);
        return res % mod;
    }
};

int main()
{
    Solution s;
    //cout<<s.numMusicPlaylists(2, 3, 1)<<endl;
    cout<<s.numMusicPlaylists(37, 50, 8)<<endl;
}