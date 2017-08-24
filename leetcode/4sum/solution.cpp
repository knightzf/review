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

    struct Comp
    {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) const
        {
            return std::tie(a[0],a[1],a[2],a[3]) < std::tie(b[0],b[1],b[2],b[3]);
        }
    };

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        std::vector<std::vector<int>> result;

        if(nums.size() < 4)
            return result;

        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>, Comp> tempMap;

        for(size_t i = 0, sz = nums.size() - 3; i < sz; ++i)
        {
            for(size_t j = i + 1; j < sz + 1; ++j)
            {
                size_t m = j + 1;
                size_t n = nums.size() - 1;

                while(m < n)
                {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    int sign = sum > target ? 1 : (sum < target ? -1 : 0);

                    switch(sign)
                    {
                        case 1: --n; break;
                        case -1: ++m; break;
                        case 0:
                        {
                            tempMap.insert({nums[i], nums[j], nums[m], nums[n]});
                            ++m;
                            --n;
                            break;
                        }
                    }
                }
            }
        }

        std::copy(tempMap.begin(), tempMap.end(), std::back_inserter(result));

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{-3,-2,-1,0,0,1,2,3};
    const auto& r = sol.fourSum(a, 0);
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
