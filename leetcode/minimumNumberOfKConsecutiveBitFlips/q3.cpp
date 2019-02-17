#include "header.h"

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size(), res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(A[i] == 0)
            {
                if(i + K > n) return -1;
                for(int j = i; j < i + K ; ++j)
                {
                    A[j] = A[j] == 0 ? 1 : 0;
                }
                ++res;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}

