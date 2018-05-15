#include "header.h"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(int num : nums)
            res += num - min;
        return res;
    }
};

int main()
{
    Solution s;
}
