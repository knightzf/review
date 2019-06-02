#include "header.h"

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(!s.count(n)) {
            s.insert(n);
            int t = 0;
            while(n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            if(t == 1) return true;
            n = t;
        }
        return false;
    }
};

int main()
{
    Solution s;
}