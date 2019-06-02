#include "header.h"

class Solution {
public:
    string convertToTitle(int n) {
        if(n < 27) return string(1, 'A' + n - 1);
        int t = ceil(double(n) / 26) - 1;
        return convertToTitle(t) + convertToTitle(n - 26 * t);
    }
};

int main()
{
    Solution s;
}