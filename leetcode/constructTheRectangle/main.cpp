#include "header.h"

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int high = int(sqrt(area));
        while(high > 0)
        {
            if(area % high == 0)
                return {area/high, high};
            --high;
        }
    }
};

int main()
{
    Solution s;
}
