#include "header.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        vector<int> leftDp(n, 0);
        vector<int> rightDp(n, 0);

        leftDp[0] = height[0];
        rightDp[n - 1] = height[n - 1];
        for(int i = 1; i < n; ++i)
        {
            leftDp[i] = max(leftDp[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; --i)
        {
            rightDp[i] = max(rightDp[i + 1], height[i]);
        }

        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            int m = min(leftDp[i], rightDp[i]);
            if(m > height[i]) res += m - height[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
}