#include "header.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int h = 2000000000;
        while(l != h)
        {
            int k = (l + h) / 2;
            int t = 0;
            for(int n : piles)
            {
                if(n <= k) ++t;
                else {
                    t += n / k;
                    if(n % k != 0) ++t;
                }
            }
            if(t <= H)
            {
                h = k;
            }
            else
            {
                l = k + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution s;
}

