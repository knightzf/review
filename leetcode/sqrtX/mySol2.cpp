#include "header.h"

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 1, h = x;
        int res = 0;
        while(l <= h)
        {
            int m = l + (h - l) / 2;
            int t = x / m;
            if(t == m) return m;
            if(t < m) h = m - 1;
            else {
                res = m;
                l = m + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.mySqrt(8)<<endl;
}