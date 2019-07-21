#include "header.h"

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int res = 0;
        for(int s1 : {-1, 1}) {
            for(int s2 : {-1, 1}) {
                int minimum = INT_MAX, maximum = INT_MIN;
                for(int i = 0; i < n; ++i) {
                    int t = s1 * arr1[i] + s2 * arr2[i] + i;
                    minimum = min(minimum, t);
                    maximum = max(maximum, t);
                }
                res = max(res, maximum - minimum);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
