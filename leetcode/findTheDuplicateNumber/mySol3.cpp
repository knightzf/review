#include "header.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0, n = nums.size(); i < n; ++i) {
            if(nums[i] != i + 1) {
                if(nums[nums[i] - 1] == nums[i]) return nums[i];
                swap(nums[nums[i] - 1], nums[i]);
                --i;
            }
        }
        return -1;
    }
};
int main() {

}