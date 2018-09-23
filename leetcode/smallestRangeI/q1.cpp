#include "header.h"

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int n = A.size();
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
            minNum = min(minNum, A[i]);
            maxNum = max(maxNum, A[i]);
        }
        if(minNum + K >= maxNum - K) return 0;
        return maxNum - K - minNum - K;
    }
};

int main()
{
    //Solution s;
}
