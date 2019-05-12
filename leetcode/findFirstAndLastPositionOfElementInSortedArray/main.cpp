#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                int i = mid, j = mid;
                while(i - 1 >= 0 && nums[i - 1] == target) --i;
                while(j + 1 < n && nums[j + 1] == target) ++j;
                return {i, j};
            }

            if(nums[mid] > target) high = mid;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};


int main()
{
    Solution s;
}