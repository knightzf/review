#include "header.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y;
        int res = 0;
        while(r)
        {
            if(r & 1) ++res;
            r >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.hammingDistance(1, 4)<<std::endl;
}
