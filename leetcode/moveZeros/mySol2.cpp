#include "header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && nums[i] != 0) ++i;
            if(j <= i) j = i + 1;
            while(j < n && nums[j] == 0) ++j;
            if(i < n && j < n) {
                swap(nums[i], nums[j]);
                ++i; ++j;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a{0,1,0,3,12};
    s.moveZeroes(a);
}