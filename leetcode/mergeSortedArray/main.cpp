#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        int sz = nums1.size();
        while(j < n)
        {
            if(i < m && nums1[i] <= nums2[j])
            {
                ++i;
            }
            else
            {
                if(i < m)
                {
                    nums1.insert(nums1.begin() + i, nums2[j]);
                    nums1.resize(sz);
                }
                else
                {
                    nums1[i] = nums2[j];
                }
                ++i;
                ++j;
                ++m;
            }
        }
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 2, 3, 0, 0, 0};
    //vector<int> b{2, 5, 6};
    vector<int> a{4, 5, 6, 0, 0, 0};
    vector<int> b{1, 2, 3};
    s.merge(a, 3, b, 3);
}
