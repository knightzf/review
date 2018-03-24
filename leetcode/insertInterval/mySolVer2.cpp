#include "header.h"

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()) return {newInterval};

        int n = intervals.size();
        int i = 0, j = n;
        while(i + 1 < j)
        {
            int m = (i + j) / 2;
            if(intervals[m].start <= newInterval.start)
                i = m;
            else
                j = m;
        }

        vector<Interval> res;
        j = 0;
        if(intervals[i].start > newInterval.start)
        {
            j = i;
        }
        else if(intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start)
        {
            res.insert(res.end(), intervals.begin(), intervals.begin() + i);
            newInterval.start = intervals[i].start;
            j = i;
        }
        else
        {
            res.insert(res.end(), intervals.begin(), intervals.begin() + i + 1);
            j = i + 1;
        }

        for(; j < n; ++j)
        {
            if(intervals[j].start > newInterval.end)
                break;
        }

        if(intervals[j - 1].end >= newInterval.end)
            newInterval.end = intervals[j - 1].end;

        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin() + j, intervals.end());

        return res;
    }
};

int main()
{
    Solution s;
    /*vector<Interval> a{Interval(1, 2),Interval(3, 5),Interval(6, 7),Interval(8, 10),Interval(12, 16)};
    const auto& r = s.insert(a, Interval(4, 9));
    vector<Interval> a{Interval(1, 3),Interval(6, 9)};
    const auto& r = s.insert(a, Interval(2, 5));*/
    vector<Interval> a{Interval(1, 5)};
    const auto& r = s.insert(a, Interval(0, 3));
    for(const auto& p : r)
    {
        std::cout<<p.start <<" "<<p.end<<std::endl;
    }
}
