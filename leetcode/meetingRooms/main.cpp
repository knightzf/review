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

class Solution {
public:
    struct my_compare {
      bool operator() (const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
      };
    };

    bool canAttendMeetings(vector<Interval>& intervals) {
        std::multiset<std::pair<int, int>, my_compare> s;
        for(const auto& i : intervals)
        {
            s.insert(std::make_pair(i.start, 1));
            s.insert(std::make_pair(i.end, -1));
        }

        int startCount = 0;

        for(const auto& p : s)
        {
            if(p.second > 0)
            {
                if(startCount != 0) return false;
                ++startCount;
            }
            else
            {
                --startCount;
            }
        }

        return true;
    }
};


int main() {
    Solution s;
}
