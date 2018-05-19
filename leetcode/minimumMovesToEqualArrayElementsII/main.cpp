#include "header.h"

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n /2, nums.end());
        int v = *(nums.begin() + n / 2);
        int res = 0;
        for(int num : nums)
        {
            res += abs(v - num);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}
