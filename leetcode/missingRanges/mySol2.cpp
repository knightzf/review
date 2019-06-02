#include "header.h"

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        auto helper = [](int l, int h) {
            string t = to_string(l);
            if(h > l) t += "->" + to_string(h);
            return t;
        };
        if(nums[0] != lower) {
            res.emplace_back(helper(lower, nums[0] - 1));
        }
        for(int i = 1, n = nums.size(); i < n; ++i) {
            if(nums[i] != nums[i - 1] + 1) {
                res.emplace_back(helper(nums[i - 1] + 1, nums[i] - 1));
            }
        }
        if(nums.back() != upper) {
            res.emplace_back(helper(nums.back() + 1, upper));
        }
        return res;
    }
};

int main()
{
    //Solution s;    
}