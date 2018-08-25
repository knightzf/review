#include "header.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i + 1) return {nums[i], i + 1};
        }
    }
};

int main() {
    Solution s;
    vector<int> a{4, 1, 2, 2};
    s.findErrorNums(a);
}
