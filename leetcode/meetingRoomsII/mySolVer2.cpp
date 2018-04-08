#include "header.h"

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::vector<pair<int, int>> v;
        for(const auto& p : intervals)
        {
            v.push_back(make_pair(p.start, 1));
            v.push_back(make_pair(p.end, -1));
        }

        std::sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                    if(a.first < b.first) return true;
                    else if(a.first == b.first) return a.second > b.second;
                    return false;
                  });

        int res = 0;
        int t = 0;
        for(const auto& p : v)
        {
            if(p.second) ++t;
            else --t;
            res = max(res, t);
        }
        return res;
    }
};

int main()
{
    Solution s;
}
