#include "header.h"

class Solution {
public:
    int primePalindrome(int N) {
       while(true)
       {
           if(isPalin(N))
           {
               if(isPrime(N)) return N;
           }

           ++N;
       }
    }

    bool isPalin(int n)
    {
        int digit = log10(n);
        while(digit > 0)
        {
            int t = int(pow(10, digit));
            int a = n / t;
            int b = n % 10;
            if(a != b) return false;
            n = n % t;
            n = n / 10;
            digit -= 2;
        }
        return true;
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
    cout<<s.primePalindrome(9989900)<<endl;
}
