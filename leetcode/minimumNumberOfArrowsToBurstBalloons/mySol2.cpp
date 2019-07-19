#include "header.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int minEnd = points[0][1];
        int res = 1;
        for(int i = 1, n = points.size(); i < n; ++i) {
            if(points[i][0] <= minEnd) continue;
            ++res;
            minEnd = points[i][1];
        }
        return res;
    }
};

int main()
{
    //Solution s;
}