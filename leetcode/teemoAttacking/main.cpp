#include "header.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int prev = -1;
        for(int t : timeSeries)
        {
            if(prev == -1)
            {
                prev = t;
            }
            else
            {
                if(t >= prev + duration)
                {
                    res += duration;
                }
                else
                {
                    res += t - prev;
                }
                prev = t;
            }
        }
        if(!timeSeries.empty()) res += duration;
        return res;
    }
};

int main()
{
    Solution s;
}
