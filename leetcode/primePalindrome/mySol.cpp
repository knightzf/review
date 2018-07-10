#include "header.h"

class Solution {
public:
    int primePalindrome(int N) {
       int digits = log10(N) + 1;
       int half = N / (pow(10, digits / 2));
       while(true)
       {
            bool isEven = digits % 2 == 0;
            int top = pow(10, isEven ? (digits / 2) : (digits / 2 + 1));
            //cout<<half<<" "<<top<<endl;
            for(int i = half; i < top; ++i)
            {
                int t = i * pow(10, digits / 2) + revert(i, isEven);
                //cout<<t<<endl;
                if(t >= N && isPrime(t)) return t;
            }
            ++digits;
            half = isEven ? top : (top / 10);
       }
    }

    int revert(int n, bool isEven)
    {
        int res = 0;
        while(n)
        {
            if(isEven)
            {
                res = res * 10 + n % 10;
            }
            else
            {
                isEven = true;
            }

            n /= 10;
        }
        return res;
    }

    bool isPrime(int n)
    {
        int t = sqrt(n);
        if(t * t == n) return false;
        for(int i = 2; i <= t; ++i)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.primePalindrome(8)<<endl;
}
