#include "header.h"

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxSize = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                for(int k = j + 1; k < n; ++k)
                {
                    maxSize = max(maxSize, calc(points[i], points[j], points[k]));
                }
            }
        }
        return maxSize;
    }

    double calc(vector<int>& p1, vector<int>& p2, vector<int>& p3)
    {
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        int x3 = p3[0], y3 = p3[1];
        return fabs(0.5 * (x2*y3 + x1*y2 + x3*y1 - x3*y2 - x2*y1- x1*y3));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {0, 0},
        {0, 1},
        {1, 0},
        {0, 2},
        {2, 0}
    };
    std::cout<<s.largestTriangleArea(a)<<std::endl;
}
