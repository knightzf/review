#include "header.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; ++i)
        {
            a[i] = A[i] + i;
            b[i] = A[i] - i;
        }

        int maxSofar = 0;
        int res = INT_MIN;
        for(int i = 1; i < n; ++i)
        {
            maxSofar = max(maxSofar, a[i - 1]);
            res = max(res, maxSofar + b[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
}

