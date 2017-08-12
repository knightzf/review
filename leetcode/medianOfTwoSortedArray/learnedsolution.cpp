#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
            std::swap(nums1, nums2);
            
        size_t m = nums1.size();
        size_t n = nums2.size();
        
        size_t start = 0;
        size_t end = m;
        
        while(true)
        {
            size_t i = (start + end) / 2;
            size_t j = (m + n + 1) / 2 - i;
            
            bool cond1 = false;
            bool cond2 = false;
            
            if(i == 0 || j == n || nums1[i-1] <= nums2[j])
                cond1 = true;
                
            if(j == 0 || i == m || nums2[j-1] <= nums1[i])
                cond2 = true;
                
            if(cond1 && cond2)
            {
                int max_of_left = 0;
                if (i == 0) 
                    max_of_left = nums2[j-1];
                else if(j == 0)
                    max_of_left = nums1[i-1];
                else
                    max_of_left = std::max(nums1[i-1], nums2[j-1]);

                if ((m + n) % 2 == 1)
                    return max_of_left;

                int min_of_right = 0;
                if (i == m)
                    min_of_right = nums2[j];
                else if(j == n)
                    min_of_right = nums1[i];
                else
                    min_of_right = std::min(nums1[i], nums2[j]);

                return (max_of_left + min_of_right) / 2.0;
            }
            else if(cond1 == false) //nums[i-1] is too large, need to decrease i
            {
                end = i - 1;
            }
            else if(cond2 == false) //nums2[j-1] is too large, need to decrease j, which is to increase i
            {
                start = i + 1;
            }
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1, 4, 6, 7};
    std::vector<int> b{2, 5, 9};
    std::cout<<sol.findMedianSortedArrays(a, b)<<std::endl;
	return 0;
}