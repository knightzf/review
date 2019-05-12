#include "header.h"

class Solution {
public:
    int climbStairs(int n) {
        int curr = 0, prev = 1, pprev = 0;
        for(int i = 1; i <= n; ++i)
        {
            curr = prev + pprev;
            pprev = prev;
            prev = curr;
        }
        return curr;
    }
};

int main()
{
    Solution s;
    
}