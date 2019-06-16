#include "header.h"

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for(const auto& p : intervals) {
            start.emplace_back(p[0]);
            end.emplace_back(p[1]);
        }

        for(int i = 0, j = 0, n = start.size(); i < n; ) {
            if(i - j > 1) return false;
            if(start[i] < end[j]) ++i;
            else if(start[i] <= end[j]) ++j;
        }
        return true;
    }
};

int main()
{
    //Solution s;
}