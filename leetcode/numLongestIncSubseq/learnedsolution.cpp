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

    void findMaxLen(const vector<int>& nums, std::map<size_t, std::pair<int, int>>& lenMap, size_t idx)
    {
        int len = 1;
        std::map<int, int> lenCountMap;
        for(size_t i = 0; i < idx; ++i)
        {
            if(nums[i] < nums[idx])
            {
                int temp = lenMap[i].first;
                auto iter = lenCountMap.find(temp);
                lenCountMap[temp] += lenMap[i].second;
            }
        }

        lenMap.insert(std::make_pair(idx,
                                     std::make_pair(len + (lenCountMap.empty() ? 0 : lenCountMap.rbegin()->first),
                                                    (lenCountMap.empty() ? 1 : lenCountMap.rbegin()->second))
                                    )
                     );
    }

    int findNumberOfLIS(vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }

        std::map<size_t, std::pair<int, int>> lenMap;

        for(size_t i = 0; i < nums.size(); ++i)
        {
            findMaxLen(nums, lenMap, i);
        }

        std::map<int, int> countMap;

        for(auto& item : lenMap)
        {
            //std::cout<<nums[item.first]<<" "<<item.second.first<<" "<<item.second.second <<std::endl;
            auto iter = countMap.find(item.second.first);
            countMap[item.second.first] += item.second.second;
        }

        return countMap.rbegin()->second;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1,2,4,3,5,4,7,2};
    //std::vector<int> a{1,3,5,4,7};
    std::cout<<sol.findNumberOfLIS(a)<<std::endl;
    return 0;
}
