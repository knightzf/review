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
    vector<vector<int>> helper(const std::set<int>& numbers, int currentNum, int target)
    {
        vector<vector<int>> result;

        auto iter = numbers.lower_bound(currentNum);
        for(; iter != numbers.end(); ++iter)
        {
            int num = *iter;
            if(num > target)
            {
                break;
            }

            if(num == target)
            {
                result.push_back(std::vector<int>{num});
            }
            else
            {
                const auto& tResult = helper(numbers, num, target - num);
                for(const auto& v : tResult)
                {
                    std::vector<int> t{num};
                    t.insert(t.end(), v.begin(), v.end());
                    result.push_back(t);
                }
            }
        }

        return result;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::set<int> numbers(candidates.begin(), candidates.end());

        vector<vector<int>> result;

        for(auto num : numbers)
        {
            if(num > target)
            {
                break;
            }

            if(num == target)
            {
                result.push_back(std::vector<int>{num});
            }
            else
            {
                const auto& tResult = helper(numbers, num, target - num);
                for(const auto& v : tResult)
                {
                    std::vector<int> t{num};
                    t.insert(t.end(), v.begin(), v.end());
                    result.push_back(t);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{2, 3, 6, 7};
    int target = 7;

    const auto& r = sol.combinationSum(a, target);
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
