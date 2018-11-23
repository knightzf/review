#include "header.h"

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        if(n == 1) return 0;
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n - 1; ++j)
            {
                if(A[j][i] > A[j + 1][i])
                {
                    ++res;
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
    vector<string> a{"zyx", "wvu", "tsr"};
    s.minDeletionSize(a);
}
