#include "header.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return A;
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
