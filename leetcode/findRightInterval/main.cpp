#include "header.h"

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, vector<int>> m;
        for(int i = 0; i < intervals.size(); ++i)
        {
            m[intervals[i].start].push_back(i);
        }

        vector<int> res;
        for(int i = 0; i < intervals.size(); ++i)
        {
            auto iter = m.lower_bound(intervals[i].end);
            if(iter != m.end())
            {
                res.push_back(iter->second[0]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
