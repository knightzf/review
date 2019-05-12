#include "header.h"

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int sign = 1;
        bool seeNum = false;
        for(int i = 0, n = str.size(); i < n; ++i)
        {
            if(isdigit(str[i]))
            {
                seeNum = true;
                res = res * 10 + (str[i] - '0');
                if(res * sign > INT_MAX) return INT_MAX;
                if(res * sign < INT_MIN) return INT_MIN;
            }
            else
            {
                if(seeNum) break;
                if(str[i] == ' ') continue;
                else if(str[i] == '-')
                {
                    seeNum = true;
                    sign = -1;
                }
                else if(str[i] == '+')
                {
                    seeNum = true;
                }
                else
                {
                    return 0;    
                }
            }
        }
        return res * sign;
    }
};

int main()
{
    Solution s;
}