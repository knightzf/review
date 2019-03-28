#include "header.h"

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> minVec(n);
        for(int i = n - 1; i >= 0; --i)
        {
            if(i == n - 1) minVec[i] = A[i];
            else minVec[i] = min(minVec[i + 1], A[i]);
        }

        int maxVal = -1;
        for(int i = 0; i < n - 1; ++ i)
        {
            maxVal = max(maxVal, A[i]);
            if(maxVal <= minVec[i + 1]) return i + 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
}