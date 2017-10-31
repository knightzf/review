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
    int smallestDistancePair(vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = INT_MAX;
        for(int i = 1; i < n; ++i)
        {
            low = std::min(nums[i] - nums[i - 1], low);
        }

        int high = nums[n - 1] - nums[0];

        while(low < high)
        {
            std::cout<<low<<" "<<high<<std::endl;
            int mid = low + (high - low) / 2;

            if (countPairs(nums, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }

    int countPairs(vector<int>& nums, int target)
    {
        int n = nums.size();
        int res = 0;

        int j = 0;
        for(int i = 0; i < n; ++i)
        {
            while(j < n && nums[j] - nums[i] <= target)
            {
                ++j;
            }

            res += j - i - 1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums{1, 3, 1};
    std::cout<<sol.smallestDistancePair(nums, 1)<<std::endl;
}
