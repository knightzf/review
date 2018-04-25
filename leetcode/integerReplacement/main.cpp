#include "header.h"

class Solution {
public:
    int integerReplacement(long n) {
        static unordered_map<long, int> m;
        if(n == 1) return 0;
        if(m.find(n) != m.end()) return m[n];
        int r = 0;
        if(n % 2 == 0) r = 1 + integerReplacement(n / 2);
        else r = 1 + min(integerReplacement(n + 1), integerReplacement(n - 1));
        m[n] = r;
        return r;
    }
};

int main()
{
    Solution s;
}
