#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, maxSum = 0;
        for(int i = 0; i < k; ++i)
        {
            maxSum += nums[i];
        }
        sum = maxSum;

        for(int i = k; i < n; ++i)
        {
            sum += nums[i] - nums[i - k];
            maxSum = max(maxSum, sum);
        }
        return maxSum / double(k);
    }
};


int main() {
    Solution s;
}
