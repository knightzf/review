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
    int findElement(vector<int>& nums, int target, int start, int end)
    {
        if(nums.empty())
        {
            return -1;
        }

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

        if(nums[start] <= target && nums[mid] >= target)
        {
            return findElement(nums, target, start, mid);
        }

        return findElement(nums, target, mid, end);
    }
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int idx = findElement(nums, target, 0, nums.size() - 1);

        if(idx == -1)
        {
            return std::vector<int>{-1, -1};
        }

        int start = idx;
        int end = idx;

        while(true)
        {
            --start;
            if(start < 0 || nums[start] != target)
            {
                ++start;
                break;
            }
        }

        while(true)
        {
            ++end;

            if(end == nums.size() || nums[end] != target)
            {
                --end;
                break;
            }
        }

        return std::vector<int>{start, end};
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{2, 2};
    auto r = sol.searchRange(a, 1);
    for(const auto& i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
