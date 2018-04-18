#include "header.h"

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 1;
        long r = n;

        while(true)
        {
            int m = (l + r) / 2;
            int rcode = guess(m);
            if(rcode == -1)
            {
                r = m - 1;
            }
            else if(rcode == 1)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }
    }
};

int main()
{
    Solution s;
}
