#include "header.h"

class Solution {
public:
    int arrangeCoins(int n) {
        if(n == 0) return 0;
        double x = 2.0 * n;
        int t = ceil(sqrt(x));
        for(int i = t - 1; i > 0; --i)
        {
            if(double(i) * i + i <= x)
                return i ;
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.arrangeCoins(1804289383)<<std::endl;
}
