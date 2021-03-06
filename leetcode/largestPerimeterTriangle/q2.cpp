#include "header.h"

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size() >= 3)
        {
            sort(A.begin(), A.end());
            for(int i = A.size() - 1; i >= 2; --i)
            {
                if(A[i] < A[i - 1] + A[i - 2]) return A[i] + A[i - 1] + A[i - 2];
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
}
