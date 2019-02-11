#include "header.h"

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X == Y) return 0;
        if(X > Y) return X - Y;
        if(Y & 1) return 1 + brokenCalc(X, Y + 1);
        return 1 + brokenCalc(X, Y / 2);
    }
};

int main()
{
    Solution s;
}

