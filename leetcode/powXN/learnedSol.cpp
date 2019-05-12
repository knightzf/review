#include "header.h"

class Solution {
public:
    double myPow(double x, int n) {
        return impl(x, n);
    }
    double impl(double x, long n)
    {
        if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
    }
};

int main()
{
    Solution s;
    cout<<s.myPow(2, 10)<<endl;
}