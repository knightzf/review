#include "header.h"

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int diff = A.back() - A[0];
        for(int i = 0; i < n - 1; ++i)
        {
            int a = A[0] + K;
            int b = A[i] + K;
            int c = A[i + 1] - K;
            int d = A.back() - K;
            diff = min(diff, max(a, max(b, max(c, d))) - min(a, min(b, min(c, d))));
        }
        return diff;
    }
};

int main()
{
    Solution s;
}

