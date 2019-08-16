#include "header.h"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + nums[i];

        vector<int> left(n, 0);
        for(int i = k; i < n; ++i) {
            left[i] = left[i - 1];
            if(sum[left[i] + k] - sum[left[i]] < sum[i + 1] - sum[i - k + 1])
                left[i] = i - k + 1;
        }
        vector<int> right(n, n - k);
        for(int i = n - k - 1; i >= k - 1; --i) {
            right[i] = right[i + 1];
            if(sum[right[i] + k] - sum[right[i]] <= sum[i + k] - sum[i])
                right[i] = i;
        }
        //for(int i : left) cout<<i<<" "; cout<<endl;
        //for(int i : right) cout<<i<<" "; cout<<endl;

        int maxSum = 0;
        vector<int> res{0, 0, 0};
        for(int i = k; i <= n - 2 * k; ++i) {
            int t = sum[left[i - 1] + k] - sum[left[i - 1]] +
                    sum[i + k] - sum[i] +
                    sum[right[i + k] + k] - sum[right[i + k]];
            if(t > maxSum) {
                maxSum = t;
                res = {left[i - 1], i, right[i + k]};
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}