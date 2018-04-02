#include "header.h"

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval&b){
                  return a.start < b.start;
                  });
        for(int i = 0; i < n; ++i)
        {
            if(i < n - 1 && intervals[i].end >= intervals[i + 1].start)
            {
                intervals[i + 1].start = intervals[i].start;
                intervals[i + 1].end = max(intervals[i].end, intervals[i + 1].end);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
