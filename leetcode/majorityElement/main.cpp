#include "header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i = 1, n = nums.size(); i < n; ++i) {
            if(count == 0) {
                major = nums[i];
                ++count;
            } else if(major == nums[i]) {
                ++count;
            } else --count;
        }
        return major;
    }
};

int main()
{
    Solution s;
}