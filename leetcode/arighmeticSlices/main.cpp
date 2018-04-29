#include "header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int res = 0;
        for(int i = 0; i < n - 2;)
        {
            int j = i + 1;
            int diff = A[j] - A[i];
            while(j < n && A[j] - A[j - 1] == diff) ++j;
            if(j - i >= 3)
            {
                res += ((j - i) * (j - i) - 3 * (j - i) + 2) / 2;
                i = j;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
