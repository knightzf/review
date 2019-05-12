#include "header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int low = 0, high = n;
        while(low < high) {
            int mid = (low + high) / 2;
            if(newInterval[0] > intervals[mid][1]) low = mid + 1;
            else high = mid;
        }

        vector<vector<int>> res;
        res.insert(res.end(), intervals.begin(), intervals.begin() + low);

        while(low < n) {
            if(newInterval[1] >= intervals[low][0]) {
                newInterval[0] = min(newInterval[0], intervals[low][0]);
                newInterval[1] = max(newInterval[1], intervals[low][1]);
                ++low;
            }
            else break;
        }

        res.emplace_back(newInterval);
        res.insert(res.end(), intervals.begin() + low, intervals.end());
        return res;
    }
};


int main()
{
    Solution s;
}