#include "header.h"

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;
        int i = 0;
        while(i < n - 1 && A[i] < A[i + 1]) ++i;
        if(i == 0 || i == n - 1) return false;
        while(i < n - 1 && A[i] > A[i + 1]) ++i;
        if(i != n - 1) return false;
        return true;
    }
};

int main()
{
    //Solution s;
}
