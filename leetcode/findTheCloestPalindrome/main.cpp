#include "header.h"

class Solution {
public:
    using ll = long long;
    string nearestPalindromic(string n) {
        ll num = stoll (n);
        int digits = log10(num) + 1;

        long first = num / pow(10, digits / 2);

        ll a = 0, b = 0;

        long lower = first;
        while(true)
        {
            long power = pow(10, digits / 2);
            bool even = digits % 2 == 0;
            long higher = pow(10, digits / 2 + 1);
            bool found = false;
            for(long i = lower; i < higher; ++i)
            {
                ll t = (long)i * power + revert(i, even);
                if(t > num)
                {
                    a = t;
                    found = true;
                    break;
                }
            }

            if(found) break;

            ++digits;
            lower = digits % 2 == 0 ? (higher / 10) : higher;
        }

        long higher = first;
        while(true)
        {
            long power = pow(10, digits / 2);
            bool even = digits % 2 == 0;
            long lower = pow(10, even ? (digits / 2 - 1) : (digits / 2));
            bool found = false;
            //cout<<lower<<" "<<higher<<endl;
            for(long i = higher; i >= lower; --i)
            {
                ll t = i * power + revert(i, even);
                if(t < num)
                {
                    b = t;
                    found = true;
                    break;
                }
            }

            if(found) break;
            --digits;
            higher = digits % 2 == 0 ? (lower - 1) : (lower * 10 - 1);
        }
        cout<<a<<" "<<b<<endl;

        if(num - b <= a - num)
            return to_string(b);
        return to_string(a);
    }

    long revert(long num, bool even)
    {
        long res = 0;
        while(num)
        {
            if(even)
                res = res * 10 + num % 10;
            else
                even = true;

            num /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.nearestPalindromic("807045053224792883");
}
