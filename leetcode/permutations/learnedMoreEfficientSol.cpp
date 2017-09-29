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
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> result;

        impl(nums, 0, result);

        return result;
    }

    void impl(vector<int>& nums, int startIdx, std::vector<std::vector<int>>& result)
    {
        if(startIdx == nums.size() - 1)
        {
            result.push_back(nums);
            return;
        }

        for(int i = startIdx; i < nums.size(); ++i)
        {
            std::swap(nums[startIdx], nums[i]);
            impl(nums, startIdx + 1, result);
            std::swap(nums[startIdx], nums[i]);
        }
    }

};

int main()
{
    Solution sol;
    //std::vector<int> a{2, 3, 1, 1, 4};
    std::vector<int> a{1, 2, 3};
    const auto& r = sol.permute(a);
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
