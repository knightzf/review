#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        auto cmp = [](const Interval& a, const Interval& b){
                        return a.start < b.start;
                   };

        std::sort(intervals.begin(), intervals.end(), cmp);

        auto iter = std::lower_bound(intervals.begin(), intervals.end(), newInterval, cmp);

        auto beginIter = intervals.end();

        if(iter == intervals.begin())
        {
            if(intervals.empty())
            {
                intervals.push_back(newInterval);
                beginIter = intervals.end();
            }
            else if(hasOverlap(*iter, newInterval))
            {
                iter->start = newInterval.start;
                if(iter->end < newInterval.end)
                {
                    iter->end = newInterval.end;
                    beginIter = iter;
                }
            }
            else
            {
                intervals.insert(iter, newInterval);
                beginIter = intervals.end();
            }
        }
        else if(iter == intervals.end())
        {
            if(intervals.back().end >= newInterval.start)
            {
                intervals.back().end = std::max(intervals.back().end, newInterval.end);
            }
            else
            {
                intervals.push_back(newInterval);
                beginIter = intervals.end();
            }
        }
        else
        {
            --iter;
            auto preIter = iter;
            ++iter;

            if(hasOverlap(*preIter, newInterval))
            {
                preIter->start = std::min(preIter->start, newInterval.start);
                preIter->end = std::max(preIter->end, newInterval.end);

                beginIter = preIter;
            }
            else if(hasOverlap(*iter, newInterval))
            {
                iter->start = std::min(iter->start, newInterval.start);
                iter->end = std::max(iter->end, newInterval.end);

                beginIter = iter;
            }
            else
            {
                intervals.insert(iter, newInterval);
                beginIter = intervals.end();
            }
        }

        for(auto i = beginIter; i != intervals.end(); )
        {
            auto currIter = i;
            while(true)
            {
                if(currIter == i)
                {
                    ++currIter;
                }

                if(currIter == intervals.end())
                {
                    i = currIter;
                    break;
                }

                if(hasOverlap(*i, *currIter))
                {
                    i->start = std::min(i->start, currIter->start);
                    i->end = std::max(i->end, currIter->end);

                    currIter = intervals.erase(currIter);
                }
                else
                {
                    i = currIter;
                    break;
                }
            }
        }

        return intervals;
    }

private:
    bool hasOverlap(const Interval& a, const Interval& b)
    {
        const Interval& left = a.start <= b.start ? a : b;
        const Interval& right = a.start <= b.start ? b : a;

        if(left.end >= right.start ||
           (left.start <= right.start && left.end >= right.end) ||
           (right.start <= left.start && right.end >= left.end))
        {
            return true;
        }

        return false;
    }
};


int main()
{
    Solution sol;
    std::vector<Interval> a{Interval(3, 5), Interval(12, 15)};
    //std::vector<Interval> a;
    sol.insert(a, Interval(6, 6));
    return 0;
}
