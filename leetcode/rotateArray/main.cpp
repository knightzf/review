#include "header.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == 0) return;
        vector<int> v; v.reserve(k);
        for(int i = n - k; i < n; ++i) v.push_back(nums[i]);
        for(int i = n - k - 1; i >= 0; --i) nums[i + k] = nums[i];
        for(int i = 0; i < k; ++i) nums[i] = v[i];
    }
};

int main()
{
    Solution s;
}