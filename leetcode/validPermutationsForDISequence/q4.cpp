#include "header.h"

class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, -1));
        impl(S, n, 0, dp);
        return dp[n][0];
    }

    long impl(const string& S, int n, int m, vector<vector<long>>& dp)
    {
        if(n == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        int idx = S.size() - n;
        bool decrease = S[idx] == 'D';
        int startIdx = decrease ? 1 : 0;
        int endIdx = decrease ? n : (n - 1);
        if(idx > 0)
        {
            if(S[idx - 1] == 'D')
            {
                endIdx = min(endIdx, m - 1);
            }
            else
            {
                startIdx = max(startIdx, m);
            }
        }

        //cout<<startIdx<<" "<<endIdx<<endl;
        long t = 0;
        for(int i = startIdx; i <= endIdx; ++i)
        {
            t += impl(S, n - 1, i, dp);
            t %= 1000000007;
        }
        dp[n][m] = t;
        return t;
    }
};

int main()
{
    Solution s;
    //cout<<s.numPermsDISequence("DID")<<endl;
    cout<<s.numPermsDISequence("DIDDIDIDIDIDIDIDIDIDIDIDIDIDIDID")<<endl;
}
