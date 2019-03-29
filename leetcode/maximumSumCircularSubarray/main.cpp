#include "header.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        vector<int> sum(n + 1, 0);
        vector<int> maxSumTil(n + 1, 0);
        for(int i = 1; i < n + 1; ++i)
        {
            sum[i] = sum[i - 1] + A[i - 1];
            if(i == 1) maxSumTil[i] = sum[i];
            else maxSumTil[i] = max(sum[i], maxSumTil[i - 1]);
        }
        
        vector<int> maxSumAfter(n + 1, 0);
        for(int i = n; i > 0; --i)
        {
            if(i == n) maxSumAfter[i] = sum[i];
            else maxSumAfter[i] = max(sum[i], maxSumAfter[i + 1]);
        }

        int res = INT_MIN;
        for(int i = 1; i < n + 1; ++i)
        {
            int a = maxSumAfter[i] - sum[i - 1];
            int b = sum[n] - sum[i - 1] + maxSumTil[i - 1];
            res = max(res, max(a, b));
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{-2, -3, -1};
    vector<int> a{5, -3, 5};
    cout<<s.maxSubarraySumCircular(a)<<endl;
}