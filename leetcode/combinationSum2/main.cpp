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
    vector<vector<int>> helper(const std::vector<int>& numbers, int idx, int target)
    {
        vector<vector<int>> result;

        for(int i = idx; i < numbers.size(); ++i)
        {
            if(i > idx && numbers[i] == numbers[i - 1])
                continue;

            int num = numbers[i];

            if(num > target)
            {
                break;
            }
            else if(num == target)
            {
                result.push_back(std::vector<int>{num});
            }
            else
            {
                const auto& tResult = helper(numbers, i + 1, target - num);
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

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        const vector<vector<int>>& result = helper(candidates, 0, target);

        return result;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    const auto& r = sol.combinationSum2(a, target);
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
