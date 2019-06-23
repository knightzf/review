#include "header.h"

class Solution {
public:
    int numSquares(int n) {
        static unordered_map<int, int> m;
        if(!m.count(n))
        {
            int x = int(sqrt(n));
            if(x * x == n) m[n] = 1;
            else {
                int res = n;
                for(int i = x; i >= 1; --i) {
                    int t = 1 + numSquares(n - i * i);
                    if(t < res) {
                        res = t;
                    }
                }
                m[n] = res;
            }
        }
        return m[n];
    }
};

int main()
{
    //Solution s;
}