#include "header.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), startIdx = 0, endIdx = 0, flipped = 0, res = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i <= n; ++i)
        {
            if(i == n) {
                return n;
            }
            else if(A[i] == 1) continue;
            else if(A[i] == 0 && flipped < K) ++flipped;
            else
            {
                dp[0] = i;
                res = max(res, dp[0]);
                break;
            }
        }

        for(int i = 1; i < n; ++i)
        {
            if(A[i - 1] == 0)
            {
                if(flipped > 0) --flipped;                
            }
            for(int endIdx = max(i, i - 1 + dp[i - 1]); endIdx <= n; ++endIdx)
            {
                if(endIdx == n)
                {
                    res = max(res, endIdx - i);
                    return res;
                }
                else if(A[endIdx] == 1) continue;
                else if(A[endIdx] == 0 && flipped < K) ++flipped;
                else
                {
                    dp[i] = endIdx - i;
                    res = max(res, dp[i]);
                    break;
                }
            }        
        }
        return res;
    }
};

int main()
{
    Solution s;
}

