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
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        auto r = impl(nums, 0);
        r.push_back({});

        return r;
    }

    vector<vector<int>> impl(vector<int>& nums, int startIdx)
    {
        int n = nums.size();

        if(startIdx == n)
        {
            return vector<vector<int>>();
        }

        int a = nums[startIdx];
        int endIdx = startIdx;

        while(nums[endIdx] == a && endIdx < n)
        {
            ++endIdx;
        }

        vector<vector<int>> aRes;

        for(int i = 1; i <= endIdx - startIdx; ++i)
        {
            vector<int> t;
            for(int j = 0; j < i; ++j)
            {
                t.push_back(a);
            }
            aRes.emplace_back(t);
        }

        auto bRes = impl(nums, endIdx);

        vector<vector<int>> res;
        for(const auto& i : aRes)
        {
            res.push_back(i);
        }

        if(!bRes.empty())
        {
            for(const auto& i : bRes)
            {
                res.push_back(i);
            }

            for(const auto i : aRes)
            {
                for(const auto& j : bRes)
                {
                    auto t = i;
                    t.insert(t.end(), j.begin(), j.end());
                    res.emplace_back(t);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::vector<int> a{1, 2, 2};
    const auto& b = s.subsetsWithDup(a);
    for(const auto& i : b)
    {
        for(auto j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
