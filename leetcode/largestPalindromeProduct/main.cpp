#include "header.h"

class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = pow(10, n - 1);
        for(int i = upper; i >= lower; --i)
        {
            long cand = makePalindrome(i);
            for(long j = upper; j*j >= cand; --j)
            {
                if(cand % j == 0 && cand / j <= upper)
                {
                    return cand % 1337;
                }
            }
        }
        return -1;
    }

    long makePalindrome(int i)
    {
        string s = to_string(i);
        reverse(s.begin(), s.end());
        return stol(to_string(i) + s);
    }
};

int main()
{
    Solution s;
}
