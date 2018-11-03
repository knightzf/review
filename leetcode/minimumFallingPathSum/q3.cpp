#include "header.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if(n == 1) return A[0][0];
        int res = INT_MAX;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int val = A[i][j];
                A[i][j] = val + A[i - 1][j];
                if(j > 0) A[i][j] = min(A[i][j], val + A[i - 1][j - 1]);
                if(j < n - 1) A[i][j] = min(A[i][j], val + A[i - 1][j + 1]);
                if(i == n - 1) res = min(res, A[i][j]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}

