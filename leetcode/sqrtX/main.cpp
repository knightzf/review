#include "header.h"

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int i = 1, j = x;
        while(i + 1 < j)
        {
            int m = ((long) i + j) / 2;
            int t = x / m;
            if(t < m)
                j = m;
            else if(t > m)
                i = m;
            else
                return m;
        }

        return i;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.mySqrt(4)<<std::endl;
    //std::cout<<s.mySqrt(2)<<std::endl;
    std::cout<<s.mySqrt(2147395599)<<std::endl;
}
