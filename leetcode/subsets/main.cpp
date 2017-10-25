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

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result {std::vector<int>{}};

        for(int i = 1; i <= nums.size(); ++i)
        {
            vector<vector<int>> r;
            combine(r, nums, i);
            result.insert(result.end(), r.begin(), r.end());
        }

        return result;
    }

    void combine(vector<vector<int>>& result, vector<int>& nums, int k)
    {
        impl(result, nums, k, 0);
    }

    void impl(vector<vector<int>>& result, vector<int>& nums, int k, int start)
    {
        if(k == 0)
        {
            return;
        }

        if(k == 1)
        {
            for(int i = start; i < nums.size(); ++i)
            {
                result.push_back(std::vector<int>{nums[i]});
            }
            return;
        }

        for(int i = start; i < nums.size(); ++i)
        {
            vector<vector<int>> t;
            impl(t, nums, k - 1, i + 1);
            for(auto item : t)
            {
                item.push_back(nums[i]);
                result.push_back(item);
            }
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1, 2, 3};
    const auto& r = sol.subsets(a);
    for(const auto& i : r)
    {
        for(const auto& j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
