#include "header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) ^ (divisor > 0);
        
        function<long(long, long)> impl = [&](long a, long b)
        {
            if(b > a) return 0L;
            long i = 1;
            long t = b;
            while(a >= t) {
                i <<= 1;
                t <<= 1;
            }

            return (i >> 1) + impl(a - (t >> 1), b);
        };

        long res = (sign ? -1 : 1) * impl(abs(long(dividend)), abs(long(divisor)));
        if(res > INT_MAX) return INT_MAX;
        return res;
    }
};

int main()
{
    Solution s;
}