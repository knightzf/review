#include "header.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int j = n - 1;
        for(int i = 0; i < n;)
        {
            if(i == j) break;
            if(A[i] % 2 == 0)
            {
                ++i;
            }
            else
            {
                swap(A[i], A[j]);
                --j;
            }
        }

        return A;
    }
};

int main()
{
    //Solution s;
}
