#include "header.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int start = 0;
        while(start != slow) {
            start = nums[start];
            slow = nums[slow];
        }
        return start;
    }
};

int main()
{
    Solution s;
}