#include "header.h"

class Solution {
public:
    int distinctSubseqII(string S) {
        int mod = 1e9 + 7;
        int n = S.size();
        vector<pair<long, long>> dp(n, {0, 0});
        dp[n - 1] = {1, 1};
        
        vector<pair<long, long>> m(26, {0, 0});
        m[S[n - 1] - 'a'] = {1, 1};
        
        for(int i = n - 2; i >= 0; --i)
        {
            if(S[i] != S[i + 1])
            {                
                long diff = dp[i + 1].first - (m[S[i] - 'a'].first - m[S[i] - 'a'].second);
                if(diff < 0) diff += mod;
                dp[i].second = (m[S[i] - 'a'].first == 0 ? 1 : 0) + diff;
                dp[i].first = dp[i + 1].first + dp[i].second;
            }
            else
            {
                dp[i].first = dp[i + 1].first + dp[i + 1].second;
                dp[i].second = dp[i + 1].second;
            }

            dp[i].first %= mod;
            dp[i].second %= mod;
            m[S[i] - 'a'] = dp[i];
        }
        //for(auto& p : dp)
        //    cout<<p.first<<" "<<p.second<<endl;
        return dp[0].first % mod;
    }
};

int main()
{
    Solution s;
    /*cout<<s.distinctSubseqII("abc")<<endl;
    cout<<s.distinctSubseqII("aba")<<endl;
    cout<<s.distinctSubseqII("aaa")<<endl;
    cout<<s.distinctSubseqII("lee")<<endl;
    cout<<s.distinctSubseqII("zzc")<<endl;
    cout<<s.distinctSubseqII("bebb")<<endl;
    cout<<s.distinctSubseqII("cdce")<<endl;*/
    //cout<<s.distinctSubseqII("zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn")<<endl;
    cout<<s.distinctSubseqII("izklbhtjxjiczmmqtbndzilujnglvcrimsnqqlqtpzvdgybbbgfvptgqnyvnegmktaxpwhzgxzdmjahhhcpxhqkawwbuyhectxlj")<<endl;
}
