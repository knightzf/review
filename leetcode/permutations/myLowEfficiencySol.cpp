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
        result.clear();

        impl(nums, std::vector<int>{}, std::set<int>{});

        return result;
    }
private:
    vector<vector<int>> result;

    void impl(vector<int>& nums, const vector<int>& head, const std::set<int>& excludeIdx)
    {
        if(head.size() == nums.size())
        {
            result.push_back(head);
            return;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(excludeIdx.find(i) == excludeIdx.end())
            {
                std::set<int> tExcludeIdx(excludeIdx);
                tExcludeIdx.insert(i);
                std::vector<int> tHead(head);
                tHead.push_back(nums[i]);
                impl(nums, tHead, tExcludeIdx);
            }
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
