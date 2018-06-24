#include "header.h"

class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool direction = true;
        int len = 0;
        bool side = true;

        while(true)
        {
            if(direction)
            {
                if(len + q < p)
                {
                    len += q;
                }
                else if(len + q == p)
                {
                    if(side) return 1;
                    return 2;
                }
                else
                {
                    len = p - (len + q - p);
                    direction = !direction;
                }
            }
            else
            {
                if(len - q == 0)
                {
                    return 0;
                }
                else if(len - q > 0)
                {
                    len -= q;
                }
                else
                {
                    len = q - len;
                    direction = !direction;
                }
            }

            side = !side;
        }
        return -1;
    }
};

int main()
{
    Solution s;
}
