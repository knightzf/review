#include "header.h"

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        vector<int> diff;
        for(int i = 0, n = A.size(); i < n - 1; ++i)
        {
            if(A[i] - A[i + 1] != 0)
            {
                diff.push_back(A[i] - A[i + 1]);
            }
        }

        if(!diff.empty())
        {
            int t = diff[0];
            for(int i = 1, n = diff.size(); i < n; ++i)
            {
                if(diff[i] * t < 0) return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
}
