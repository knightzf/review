#include "header.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = INT_MIN, currMax = 0, minSum = INT_MAX, currMin = 0;
        for(int num : A) {
            currMax = max(num, currMax + num);
            maxSum = max(maxSum, currMax);
            currMin = min(num, currMin + num);
            minSum = min(minSum, currMin);
            total += num;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};


int main()
{
    Solution s;
}