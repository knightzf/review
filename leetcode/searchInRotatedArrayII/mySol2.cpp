#include "header.h"

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        function<bool(int, int)> bsearch = [&](int l, int h)
        {
            if(l >= h) return false;
            int m = (l + h) / 2;
            if(nums[m] == target) return true;
            if(nums[l] < nums[m] && nums[l] <= target && target < nums[m]) 
                return bsearch(l, m);
            if(nums[m] < nums[h - 1] && nums[m] < target && target <= nums[h - 1]) 
                return bsearch(m + 1, h);
            return bsearch(l, m) || bsearch(m + 1, h);
        };
        
        return bsearch(0, nums.size());
    }
};


int main()
{
    Solution s;
    vector<int> a{1, 3};
    cout<<s.search(a, 3)<<endl;
}