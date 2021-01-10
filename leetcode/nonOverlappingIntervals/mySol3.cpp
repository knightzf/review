class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int count = 1, n = intervals.size();
        int end = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            if(intervals[i][0] >= end) {
                end = intervals[i][1];
                ++count;
            }
        }
        return n - count;
    }
};
