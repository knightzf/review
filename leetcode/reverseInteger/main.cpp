#include "header.h"

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x)
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        
        if(res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<-12%10<<endl;
}