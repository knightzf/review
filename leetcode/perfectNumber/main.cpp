#include "header.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int t = sqrt(num);
        int sum = 1;
        for(int i = 2; i <= t; ++i)
        {
            if(num % i == 0)
            {
                sum += i;
                if(num / i != i)
                    sum += num / i;
            }
        }

        if(sum == num) return true;
        return false;
    }
};

int main()
{
    Solution s;
}
