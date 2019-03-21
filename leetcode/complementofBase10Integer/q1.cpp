#include "header.h"

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int res = 0;
        int i = 0;
        while(N)
        {
            if((N & 1) == 0)
            {
                res += (1 << i);
            }

            N >>= 1;
            ++i;
        }

        return res;
    }
};

int main()
{
    Solution s;
}
