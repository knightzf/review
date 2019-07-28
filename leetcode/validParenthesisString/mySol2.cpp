#include "header.h"

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for(char c : s) {
            switch(c) {
                case '(' : ++low; ++high; break;
                case ')': --low; --high; break;
                default : --low; ++high; break;
            }
            if(high < 0) return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};

int main()
{
    //Solution s;
}