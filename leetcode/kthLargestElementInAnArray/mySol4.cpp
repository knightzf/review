#include "header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        int startIdx = 0, endIdx = n;

        while(true) {
            int idx = partition(nums, startIdx, endIdx);
            if(idx == k) return nums[idx];
            if(idx > k) endIdx = idx;
            else startIdx = idx + 1;
        }

        return -1;
    }

    int partition(vector<int>& nums, int startIdx, int endIdx) {
        int midIdx = (startIdx + endIdx) / 2;
        int pivot = nums[midIdx];
        swap(nums[midIdx], nums[endIdx - 1]);
        while(nums[startIdx] < pivot) ++startIdx;
        if(startIdx == endIdx - 1) return startIdx;        
        
        for(int i = startIdx + 1; i < endIdx - 1; ++i) {
            if(nums[i] < pivot) {
                swap(nums[startIdx++], nums[i]);
            }
        }
        swap(nums[startIdx], nums[endIdx - 1]);
        return startIdx;
    }
};

int main()
{
    Solution s;
    vector<int> a{3,2,3,1,2,4,5,5,6};
    cout<<s.findKthLargest(a, 4)<<endl;
}