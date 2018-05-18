#include "header.h"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = floor(double(minutesToTest) / minutesToDie);
        int i = 0;
        while(pow(tests + 1, i) < buckets)
            ++i;
        return i;
    }
};

int main()
{
    Solution s;
    s.poorPigs(1000, 15, 60);
}
