#include "header.h"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;
        return !canWin(nums[0], 0, 1, n - 1, nums, false) || !canWin(nums[n - 1], 0, 0, n - 2, nums, false);
    }

    bool canWin(int sum1, int sum2, int startIdx, int endIdx, vector<int>& nums, bool isP1)
    {
        if(startIdx > endIdx) return isP1 ? (sum1 >= sum2) : (sum2 > sum1);
        return !canWin((isP1 ? (sum1 + nums[startIdx]) : sum1),
                       (isP1 ? sum2 : (sum2 + nums[startIdx])), startIdx + 1, endIdx, nums, !isP1) ||
               !canWin((isP1 ? (sum1 + nums[endIdx]) : sum1),
                       (isP1 ? sum2 : (sum2 + nums[endIdx])), startIdx, endIdx - 1, nums, !isP1);
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 5, 233, 7};
    cout<<s.PredictTheWinner(a)<<endl;
}
