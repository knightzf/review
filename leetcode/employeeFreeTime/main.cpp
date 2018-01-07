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
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


struct Compare {
    bool operator() (const Interval& a, const Interval& b) const {
        return std::tie(a.start, a.end) < std::tie(b.start, b.end);
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& avails) {
        int minStart = INT_MAX;
        int maxEnd = INT_MIN;

        for(const auto& v : avails)
        {
            minStart = std::min(minStart, v[0].start);
            maxEnd = std::max(maxEnd, v.back().end);
        }

        //std::cout<<minStart<<" "<<maxEnd<<std::endl;

        Interval total(minStart, maxEnd);

        std::set<Interval, Compare> interSet;
        for(const auto& v : avails)
        {
            for(const auto& i : v)
                interSet.insert(i);
        }

        /*for(const auto& i : interSet)
        {
            std::cout<<i.start<<" "<<i.end<<std::endl;
        }*/

        vector<Interval> res;

        for(const auto& inter : interSet)
        {
            if(total.start >= inter.start && total.start <= inter.end)
            {
                total.start = inter.end;
            }
            else if(total.start >= inter.start)
            {

            }
            else
            {
                //std::cout<<total.start <<" "<< inter.start<<std::endl;
                res.push_back(Interval(total.start, inter.start));
                total.start = inter.end;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    /*vector<vector<Interval>> a{
        {Interval(1, 3),Interval(6, 7)},
        {Interval(2, 4)},
        {Interval(2, 5),Interval(9, 12)},
    };*/

    vector<vector<Interval>> a{
        {Interval(1, 2),Interval(5, 6)},
        {Interval(1, 3)},
        {Interval(4, 10)},
    };

    s.employeeFreeTime(a);
}
