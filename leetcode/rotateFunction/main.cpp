#include "header.h"

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int sum = 0, currentValue = 0;

        for(int i = 0; i < n; ++i)
        {
            sum += A[i];
            currentValue += i * A[i];
        }

        int res = currentValue;
        for(int i = 1; i < n; ++i)
        {
            currentValue = currentValue - (n - 1) * A[n - i] + sum - A[n - i];
            res = max(res, currentValue);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{4, 3, 2, 6};
    std::cout<<s.maxRotateFunction(a)<<std::endl;
}
