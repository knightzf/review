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

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;

        impl(nums, 0, result);

        return result;
    }

    void impl(vector<int> nums, int startIdx, std::vector<std::vector<int>>& result)
    {
        if(startIdx == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        std::sort(nums.begin() + startIdx, nums.end());

        for(int i = startIdx; i < nums.size(); ++i)
        {
            if(i != startIdx && nums[i] == nums[i - 1])
                continue;

            std::vector<int> tNums(nums);
            std::swap(tNums[startIdx], tNums[i]);
            impl(tNums, startIdx + 1, result);
        }
    }

};

int main()
{
    Solution sol;
    //std::vector<int> a{2, 3, 1, 1, 4};
    std::vector<int> a{0, 1, 0, 0, 9};
    const auto& r = sol.permuteUnique(a);
    for(const auto& i : r)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
