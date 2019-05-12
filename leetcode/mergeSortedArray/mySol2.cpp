#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        rotate(nums1.begin(), nums1.begin() + m, nums1.end());
        int i = n, j = 0, k = 0;
        while(i < m + n || j < n)
        {
            if(i < m + n && j < n)
            {
                if(nums1[i] <= nums2[j]) {
                    nums1[k++] = nums1[i++];
                } else {
                    nums1[k++] = nums2[j++];
                }
            }
            else if (i < m + n) {
                nums1[k++] = nums1[i++];
            }
            else nums1[k++] = nums2[j++];
        }
    }
};


int main()
{
    Solution s;
}