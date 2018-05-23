#include "header.h"

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();

        int leftIdx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(points[i][0] <= points[leftIdx][0] && points[i][1] <= points[leftIdx][1])
                leftIdx = i;
        }

        bool res = true;
        bool init = false;
        for(int i = 0; i < n; ++i)
        {
            if((points[leftIdx][0] == points[(leftIdx + 1) % n][0] &&
               points[(leftIdx + 1) % n][0] == points[(leftIdx + 2) % n][0]) ||
               (points[leftIdx][1] == points[(leftIdx + 1) % n][1] &&
                points[(leftIdx + 1) % n][1] == points[(leftIdx + 2) % n][1])
               )
            {
                leftIdx = (leftIdx + 1) % n;
                continue;
            }

            bool t = valid(points[leftIdx], points[(leftIdx + 1) % n], points[(leftIdx + 2) % n]);
            if(init == false)
            {
                init = true;
                res = t;
            }
            else if(t != res) return false;
            leftIdx = (leftIdx + 1) % n;
        }

        return true;
    }

    bool valid(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3)
    {
        if(p1[0] == p3[0])
            return p1[1] < p3[1] ? (p2[0] <= p1[0]) : (p2[0] >= p1[0]);

        if(p1[1] == p3[1])
            return p1[0] < p3[0] ? (p2[1] >= p1[1]) : (p2[1] <= p1[1]);

        double slope = double(p3[1] - p1[1]) / (p3[0] - p1[0]);
        double b = p3[1] - slope * p3[0];

        if(slope > 0)
            return p3[1] > p1[1] ? (calcY(p2, slope, b) <= p2[1]) : (calcY(p2, slope, b) >= p2[1]);
        else
            return p3[1] > p1[1] ? (calcY(p2, slope, b) >= p2[1]) : (calcY(p2, slope, b) <= p2[1]);
    }

    double calcY(const vector<int>& p, double slope, double b)
    {
        return slope * p[0] + b;
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> a{{0,0},{1,0},{1,1},{-1,1},{-1,0}};
    vector<vector<int>> a{{1,0},{0,1},{-1,0},{0,-1}};
    cout<<s.isConvex(a)<<endl;
}
