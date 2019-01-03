#include "header.h"

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        int res = 0;
        vector<int> idx(50001, 0);
        for(int i = n - 1; i >= 0; --i)
        {
            if(idx[A[i]] == 0)
            {
                for(int j = A[i]; j >= 0; --j)
                {
                    if(i > idx[j]) idx[j] = i;
                    else break;
                }
            }
            else
            {
                res = max(res, idx[A[i]] - i);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
