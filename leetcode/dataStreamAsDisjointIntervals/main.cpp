#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
    std::map<int, int> m;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        auto after = m.upper_bound(val);
        if(after != m.end())
        {
            auto before = after; --before;
            if(before != m.end())
            {
                if(before->second + 1 == val && val == after->first - 1)
                {
                    int s = before->first, e = after->second;
                    m.erase(after);
                    m[s] = e;
                }
                else if(before->second + 1 == val)
                {
                    m[before->first] = val;
                }
                else if(val == after->first - 1)
                {
                    int e = after->second;
                    m.erase(after);
                    m[val] = e;
                }
                else if(val >= before->first && val <= before->second)
                {

                }
                else
                {
                    m[val] = val;
                }
            }
            else
            {
                if(val == after->first - 1)
                {
                    int e = after->second;
                    m.erase(after);
                    m[val] = e;
                }
                else
                {
                    m[val] = val;
                }
            }
        }
        else
        {
            auto before = m.rbegin();
            if(before != m.rend())
            {
                if(before->second + 1 == val)
                    m[before->first] = val;
                else if(val >= before->first && val <= before->second)
                {

                }
                else
                    m[val] = val;
            }
            else
            {
                m[val] = val;
            }
        }
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(const auto& p : m)
        {
            res.emplace_back(Interval(p.first, p.second));
        }
        return res;
    }
};


int main() {
    //Solution s;

    SummaryRanges s;
    vector<int> a{1, 3, 7, 2, 6};
    for(int i = 0; i < a.size(); ++i)
    {
        s.addNum(a[i]);
        const auto& r = s.getIntervals();
        for(const auto& p : r)
        {
            std::cout<<"["<<p.start<<","<<p.end<< "],";
        }
        std::cout<<std::endl;
    }
}
