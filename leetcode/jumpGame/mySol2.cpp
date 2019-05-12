#include "header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodIdx = n - 1;
        for(int i = n - 1; i >= 0; --i) {
            if(i + nums[i] >= goodIdx) {
                goodIdx = i;
            }
        }
        return goodIdx == 0;
    }
};

int main()
{
    Solution s;
}