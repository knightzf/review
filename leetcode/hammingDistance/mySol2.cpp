#include "header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int res = 0;
        while(t & (t - 1)) {
            ++res;
            t = t & (t - 1);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}