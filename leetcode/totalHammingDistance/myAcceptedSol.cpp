#include "header.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int j = 0; j < 32; ++j)
        {
            int cntOfOne = 0;
            int hasNonZero = false;
            for(int i = 0; i < n; ++i)
            {
                if(nums[i] & 1) ++cntOfOne;
                nums[i] >>= 1;
                if(hasNonZero == false && nums[i]) hasNonZero = true;
            }

            res += (n - cntOfOne) * cntOfOne;

            if(!hasNonZero) break;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{4, 14, 2};
    std::cout<<s.totalHammingDistance(a)<<std::endl;
}
