#include "header.h"

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(seats[i] == 1)
            {
                if(prev == -1)
                {
                    prev = i;
                }
                else
                {
                    int t = i - prev;
                    res = max(res, t / 2);
                    prev = i;
                }
            }
        }

        if(n != 0 && seats.back() == 0)
        {
            res = max(res, n - 1 - prev);
        }
        return res;
    }
};

int main()
{
    Solution s;
}
