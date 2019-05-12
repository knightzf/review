#include "header.h"

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        for(int i = 1; i < n + 1; ++i)
        {
            sum[i] = A[i - 1] + sum[i - 1];
        }
        int res = 0;
        vector<pair<int, int>> dp(n + 1, make_pair(0, 0));
        for(int i = 1; i < n + 1; ++i)
        {
            if(i >= L) {
                dp[i].first = max(dp[i - 1].first, sum[i] - sum[i - L]);
            }
            if(i >= M)
            {
                dp[i].second = max(dp[i - 1].second, sum[i] - sum[i - M]);
            }
            if(i >= L && i >= M)
            res = max(res, max(sum[i] - sum[i - L] + dp[i - L].second,
                               sum[i] - sum[i - M] + dp[i - M].first));
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{0,6,5,2,2,5,1,9,4};
    cout<<s.maxSumTwoNoOverlap(a, 1, 2)<<endl;
}

