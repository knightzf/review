#include "header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        int l = 0, h = n;
        while(l < h) {
            int idx = rand() % (h - l) + l;
            int t = nums[idx];
            swap(nums[idx], nums[h - 1]);
            int i = l, j = h - 2;
            while(i <= j) {
                while(i < h - 1 && nums[i] <= t) ++i;
                while(j >= l && nums[j] > t) --j;
                if(i < j) {
                    swap(nums[i], nums[j]);
                    ++i; --j;
                }
            }
            swap(nums[i], nums[h - 1]);
            if(i == k) return nums[i];
            if(i > k) h = i;
            else l = i + 1;            
        }
        return nums[l];
    }
};

int main()
{
    Solution s;
    vector<int> a{3,2,3,1,2,4,5,5,6};
    cout<<s.findKthLargest(a, 4)<<endl;
}