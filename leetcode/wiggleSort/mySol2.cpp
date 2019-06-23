#include "header.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1, n = nums.size(); i < n; ++i) {
            if(i & 1) {
                if(nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
            } else if(nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
        }
    }
};

int main()
{
    //Solution s;
}