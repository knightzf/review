#include "header.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        impl(nums, res, 0, n, std::vector<int>{});
        return res;
    }

    void impl(const vector<int>& nums, vector<vector<int>>& res,
              int startIdx, int n, const vector<int>& prev)
    {
        res.push_back(prev);
        for(int i = startIdx; i < n; ++i)
        {
            if(i == startIdx || nums[i] != nums[i - 1])
            {
                vector<int> t = prev;
                t.push_back(nums[i]);
                impl(nums, res, i + 1, n, t);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 2, 2, 3};
    const auto& r = s.subsetsWithDup(a);
    for(const auto& i : r)
    {
        for(int j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
