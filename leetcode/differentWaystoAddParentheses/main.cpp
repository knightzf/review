#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        std::vector<int> nums;
        std::vector<char> opers;
        int n = input.size();
        for(int i = 0; i < n;)
        {
            if(std::isdigit(input[i]))
            {
                int j = i;
                while(j < n && std::isdigit(input[j])) ++j;
                nums.push_back(std::stoi(input.substr(i, j - i)));
                i = j;
            }
            else
            {
                opers.push_back(input[i]);
                ++i;
            }
        }

        return compute(nums, opers, 0, nums.size());
    }

    vector<int> compute(std::vector<int>& nums, std::vector<char>& opers, int numStartIdx, int numEndIdx)
    {
        if(numStartIdx + 1 == numEndIdx) return {nums[numStartIdx]};
        if(numStartIdx + 2 == numEndIdx) return {impl(nums[numStartIdx], nums[numStartIdx + 1], opers[numStartIdx])};

        std::vector<int> results;

        for(int i = numStartIdx; i < numEndIdx - 1; ++i)
        {
            const auto& r1 = compute(nums, opers, numStartIdx, i + 1);
            const auto& r2 = compute(nums, opers, i + 1, numEndIdx);

            for(int m = 0; m < r1.size(); ++m)
            {
                for(int n = 0; n < r2.size(); ++n)
                {
                    results.push_back(impl(r1[m], r2[n], opers[i]));
                }
            }
        }

        return results;
    }

    int impl(int a, int b, char oper)
    {
        switch(oper)
        {
            case '+' : return a + b;
            case '-' : return a - b;
            default: return a * b;
        }
    }
};

int main() {
    Solution s;
    const auto& r = s.diffWaysToCompute("2*3-4*5");
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
