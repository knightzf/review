#include "header.h"

class Solution {
public:
    double myPow(double x, int n) {
        long p = abs(long(n));
        long one = 1;
        vector<double> v(32, 0);
        v[0] = x;
        for(int i = 1; i < 32; ++i)
        {
            v[i] = v[i - 1] * v[i - 1];
            if((one << i) >= p) break;
        }

        double res = 1;
        for(int i = 31; p && i >= 0; --i)
        {
            if(p >= (one << i)) {
                res *= v[i];
                p -= (one << i);
            }
        }

        if(n < 0) return 1/res;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.myPow(2, 10)<<endl;
}