#include "header.h"

class Solution {
public:
    int clumsy(int N) {
        int res = N;
        int borrow = N;
        for(int i = 1, j = 1; i < N; ++i, j = (j + 1) % 4)
        {
            int n = N - i;
            if(j == 1)
            {
                res -= borrow;
                borrow *= n;      
                res += borrow;
            }  
            else if(j == 2)
            {
                res -= borrow;
                borrow /= n;      
                res += borrow;
            }
            else if(j == 3)
            {
                res += n;
            }
            else
            {
                res -= n;
                borrow = -n;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    //s.clumsy(10);
    s.clumsy(4);
}
