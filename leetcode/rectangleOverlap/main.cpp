#include "header.h"

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(overlap(rec1[0], rec1[2], rec2[0], rec2[2]) && overlap(rec1[1], rec1[3], rec2[1], rec2[3]))
            return true;
        return false;
    }

    bool overlap(int a, int b, int c, int d)
    {
        long t = (long)abs(a - b) + abs(c - d);
        int tmin = min(min(a, b), min(c, d));
        int tmax = max(max(a, b), max(c, d));
        if(t > tmax - tmin) return true;
        return false;
    }
};

int main()
{
    Solution s;
    //vector<int> a{7, 8, 13, 15};
    //vector<int> b{10, 8, 12, 20};
    vector<int> a{4, 4, 14, 7};
    vector<int> b{4, 3, 8, 8};
    cout<<s.isRectangleOverlap(a, b)<<endl;
}
