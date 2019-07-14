#include "header.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long MIN = std::numeric_limits<long>::min();
        vector<long> v(3, MIN);
        for(int i : nums) {
            if(i > v[0]) {
                v[2] = v[1];
                v[1] = v[0];
                v[0] = i;
            } else if(i == v[0]) continue;
            else if(i > v[1]) {
                v[2] = v[1];
                v[1] = i;
            } else if(i == v[1]) continue;
            else if(i >= v[2]) v[2] = i;
        }
        if(v[2] != MIN) return v[2];
        return v[0];
    }
};

int main()
{
    Solution s;
}