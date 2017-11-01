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
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int n = nums.size();

        if(n == 0)
        {
            return false;
        }

        int start = 0;
        int end = n - 1;

        while(start < end)
        {
            while(start + 1 < end && nums[start + 1] == nums[start])
            {
                ++start;
            }

            while(end - 1 > start && nums[end - 1] == nums[end])
            {
                --end;
            }

            //std::cout<<nums[start]<<" "<<nums[end]<<std::endl;

            if(start + 1 == end)
            {
                return nums[start] == target || nums[end] == target;
            }

            int mid = start + (end - start) / 2;

            if(nums[start] <= nums[mid])
            {
                if(nums[start] <= target && nums[mid] >= target)
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }

            if(nums[mid] <= nums[end])
            {
                if(nums[mid] <= target && nums[end] >= target)
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
        }

        return nums[start] == target;
    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{4, 5, 6, 7, 0, 1, 2};
    std::vector<int> a{1, 2, 1};
    std::cout<<sol.search(a, 0)<<std::endl;
}
