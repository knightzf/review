#include "header.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j)
        {
            int m = (i + j) / 2;
            if(nums[i] < nums[m])
            {
                i = m;
            }
            else if(nums[i] > nums[m])
            {
                j = m - 1;
            }
            else
            {
                i = nums[i] > nums[j] ? i : j;
                break;
            }
        }

        if(target >= nums[0] && target <= nums[i])
        {
            return binarySearch(nums, target, 0, i);
        }
        else if(i < n - 1 && target >= nums[i + 1] && target <= nums[n - 1])
        {
            return binarySearch(nums, target, i + 1, n - 1);
        }

        return -1;
    }

    int binarySearch(const vector<int>& nums, int target, int i, int j)
    {
        while(i <= j)
        {
            int m = (i + j) / 2;
            if(nums[m] == target)
                return m;
            else if(nums[m] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    //vector<int> a{4, 5, 6, 7, 0, 1, 2};
    vector<int> a{3, 1};
    std::cout<<s.search(a, 1)<<std::endl;;
}
