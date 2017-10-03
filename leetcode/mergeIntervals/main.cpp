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
    vector<Interval> merge(vector<Interval>& intervals)
    {
        std::sort(intervals.begin(), intervals.end(),
                  [](const Interval& a, const Interval& b){
                        return a.start < b.start;
                  });

        for(auto iter = intervals.begin(); iter != intervals.end(); )
        {
            auto currIter = iter;
            while(true)
            {
                if(currIter == iter)
                {
                    ++currIter;
                }

                if(currIter == intervals.end())
                {
                    iter = currIter;
                    break;
                }

                std::cout<<currIter->start<<" "<<currIter->end<<std::endl;

                if(hasOverlap(*iter, *currIter))
                {
                    iter->start = std::min(iter->start, currIter->start);
                    iter->end = std::max(iter->end, currIter->end);

                    currIter = intervals.erase(currIter);
                }
                else
                {
                    iter = currIter;
                    break;
                }
            }
        }

        return intervals;
    }

private:
    bool hasOverlap(const Interval& a, const Interval& b)
    {
        if(a.end >= b.start ||
           (a.start <= b.start && a.end >= b.end) ||
           (b.start <= a.start && b.end >= a.end))
        {
            return true;
        }

        return false;
    }

};


int main()
{
    Solution sol;
    std::vector<Interval> a{Interval(1, 4),Interval(0, 2),Interval(3, 5)};
    sol.merge(a);
    return 0;
}
