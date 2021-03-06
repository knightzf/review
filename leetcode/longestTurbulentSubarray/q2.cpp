#include "header.h"

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        vector<int> up(n, 1);
        vector<int> down(n, 1);

        int res = 1;
        for(int i = 1; i < n; ++i)
        {
            if(A[i] > A[i - 1]) up[i] = down[i - 1] + 1;
            if(A[i] < A[i - 1]) down[i] = up[i - 1] + 1;
            res = max(res, up[i]);
            res = max(res, down[i]);
        }

        return res;
    }
};

int main()
{
    Solution s;
}
