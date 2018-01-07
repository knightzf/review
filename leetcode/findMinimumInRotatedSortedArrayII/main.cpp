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
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(nums[0] < nums[n - 1]) return nums[0];

        int leftIdx = 0;
        int rightIdx = n - 1;
        return impl(nums, leftIdx, rightIdx);
    }

    int impl(vector<int>& nums, int leftIdx, int rightIdx)
    {
        if(leftIdx + 1 == rightIdx)
        {
            return std::min(nums[leftIdx], nums[rightIdx]);
        }
        else
        {
            int midIdx = (leftIdx + rightIdx) / 2;
            if(nums[leftIdx] < nums[midIdx])
            {
                return impl(nums, midIdx, rightIdx);
            }
            else if(nums[leftIdx] == nums[midIdx])
            {
                return std::min(impl(nums, leftIdx, midIdx), impl(nums, midIdx, rightIdx));
            }
            else
            {
                return impl(nums, leftIdx, midIdx);
            }
        }
    }
};


int main()
{
    Solution s;
    vector<int> a{4, 5, 6, 7, 0, 1, 2};
    std::cout<<s.findMin(a)<<std::endl;
}
