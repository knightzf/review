#include "header.h"

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        set<int> s(heaters.begin(), heaters.end());
        int res = 0;
        for(int h : houses)
        {
            if(s.find(h) == s.end())
            {
                int t = INT_MAX;
                auto iter = s.lower_bound(h);
                if(iter == s.begin())
                {
                    t = min(t, *iter - h);
                }
                else
                {
                    if(iter != s.end())
                    {
                        t = min(t, *iter - h);
                    }
                    --iter;
                    t = min(t, h - *iter);
                }
                res = max(res, t);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
