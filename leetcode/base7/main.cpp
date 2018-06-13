#include "header.h"

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int t = abs(num);
        string res;
        while(t)
        {
            res = to_string(t % 7) + res;
            t /= 7;
        }
        if(num < 0) res = "-" + res;
        return res;
    }
};

int main()
{
    Solution s;
}
