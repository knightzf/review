#include "header.h"

class Solution {
public:
    int partition(vector<vector<int>>& points, int i, int j) {
        int m = (i + j) / 2, pivot = points[m][0] * points[m][0] + points[m][1] * points[m][1];
        while(true) {
            while(points[i][0] * points[i][0] + points[i][1] * points[i][1] < pivot) ++i;
            while(points[j][0] * points[j][0] + points[j][1] * points[j][1] > pivot) --j;
            if(i >= j) return j;
            swap(points[i++], points[j--]);
        }
        return -1;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, h = points.size() - 1;
        while(true) {
            int idx = partition(points, l, h);
            if(idx == K - 1) break;
            else if(idx < K - 1) l = idx + 1;
            else h = idx;
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1, 3}, {-2, 2}, {2, -2}};
    const auto& r = s.kClosest(a, 2);
    cout<<r.size()<<endl;
}