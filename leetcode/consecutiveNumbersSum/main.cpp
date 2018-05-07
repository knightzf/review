#include "header.h"

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        int t = ceil(N / 2.0);
        for(int i = 1; i <= t; ++i)
        {
            if((i & 1) && (N % i == 0))
            {
                if(N / i  - 1 >= (i - 1) / 2)
                    ++res;
                else
                    break;
            }
            else if(!(i & 1) && (N % i) * 2 == i)
            {
                if(N / i >= i / 2)
                    ++res;
                else
                    break;
            }
            //std::cout<<i<<" "<<res<<std::endl;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.consecutiveNumbersSum(1)<<std::endl;
    std::cout<<s.consecutiveNumbersSum(5)<<std::endl;
    std::cout<<s.consecutiveNumbersSum(9)<<std::endl;
    std::cout<<s.consecutiveNumbersSum(15)<<std::endl;
    std::cout<<s.consecutiveNumbersSum(85)<<std::endl;
}
