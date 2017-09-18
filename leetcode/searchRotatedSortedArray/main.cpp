#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
    int searchImpl(vector<int>& nums, int target, int start, int end)
    {
        if(start == end)
        {
            return nums[start] == target ? start : -1;
        }

        if(start + 1 == end)
        {
            return nums[start] == target ? start : (nums[end] == target ? end : -1);
        }

        int mid = (start + end) / 2;

        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[start] < nums[mid])
        {
            if(target >= nums[start] && target <= nums[mid])
            {
                return searchImpl(nums, target, start, mid);
            }
            else
            {
                return searchImpl(nums, target, mid, end);
            }
        }
        else if(nums[mid] < nums[end])
        {
            if(target >= nums[mid] && target <= nums[end])
            {
                return searchImpl(nums, target, mid, end);
            }
            else
            {
                return searchImpl(nums, target, start, mid);
            }
        }
    }

    int search(vector<int>& nums, int target)
    {
        if(nums.empty())
        {
            return -1;
        }

        return searchImpl(nums, target, 0, nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{4, 5, 6, 7, 0, 1, 2};
    std::cout<<sol.search(a, 3)<<std::endl;
    return 0;
}
