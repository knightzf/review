#include "header.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0, e = sqrt(c); i <= e; ++i)
        {
            int t = sqrt(c - i*i);
            if(t * t + i * i == c) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
}
