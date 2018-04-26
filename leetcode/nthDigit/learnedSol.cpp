#include "header.h"

class Solution {
public:
    int findNthDigit(int n) {
        long cnt = 9;
        int len = 1;
        int start = 1;
        while(n > len * cnt)
        {
            n -= len * cnt;
            ++len;
            start *= 10;
            cnt *= 10;
        }

        start += (n - 1) / len;
        string t = std::to_string(start);
        return t[n % len - 1] - '0';
    }
};

int main()
{
    Solution s;
    std::cout<<s.findNthDigit(14)<<std::endl;
}
