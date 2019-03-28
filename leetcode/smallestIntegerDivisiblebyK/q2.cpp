#include "header.h"

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0) return -1;
        long n = 1, digits = 1, mod = n % K, lastMod = mod;
        while(digits < 1000000)
        {
            if(mod == 0) return digits;
            lastMod *= 10;
            lastMod %= K;
            mod += lastMod;
            mod %= K;
            ++digits;            
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.smallestRepunitDivByK(17)<<endl;
}
