#include "header.h"

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int mod = 1000000007;
        if(A % B == 0 || B % A == 0)
        {
            int t = min(A, B);
            return long(t) * N % mod;
        }

        int lcm = A * B / GCD(A, B);

        long l = min(A, B);
        long r = (long)N * max(A, B);
        while(true)
        {
            long m = (l + r) / 2;
            long t = m / A + m / B - m / lcm;
            if(t == N)
            {
                int cnt = 0;
                while(m % A != 0 && m % B != 0)
                    --m;

                return m % mod;
            }
            else if(t > N)
            {
                r = m - 1;
            }
            else l = m + 1;
        }
    }

    int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }
};

void test()
{
    int r = 0;
    for(int i = 1; i <= 100; ++i)
        if(i % 2 == 0 || i % 3 == 0)
            ++r;
    cout<<r<<endl;
    cout<<gcd(12, 8)<<endl;
    long a = (long)1000000000 * 40000;
    cout<<a<<endl;
}


int main()
{
    Solution s;
    /*cout<<s.nthMagicalNumber(1, 2, 3)<<endl;
    cout<<s.nthMagicalNumber(4, 2, 3)<<endl;
    cout<<s.nthMagicalNumber(5, 2, 4)<<endl;
    cout<<s.nthMagicalNumber(3, 6, 4)<<endl;*/
    cout<<s.nthMagicalNumber(1000000000, 39999, 40000)<<endl;
}

