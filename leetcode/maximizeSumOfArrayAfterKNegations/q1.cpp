#include "header.h"

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for(int i = 0, n = A.size(); i < n && K > 0; ++i)
        {
            if(A[i] < 0)
            {
                A[i] *= -1;
                --K;
            }
            else
            {
                if(K & 1)
                {
                    if(i == 0 || A[i] <= A[i - 1])
                        A[i] *= -1;
                    else
                        A[i - 1] *= -1;
                    
                    break;
                }
            }            
        }
        int res = accumulate(A.begin(), A.end(), 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{-2, 5, 0, 2, -2};
    s.largestSumAfterKNegations(a, 3);
}
