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
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<std::pair<long, long>> v;
        long newLower = lower;
        long newUpper = upper;
        for(int i = 0, sz = nums.size(); i < sz; ++i)
        {
            if(nums[i] == newLower)
            {
                newLower = (long)nums[i] + 1;
                continue;
            }
            else if(nums[i] > newLower)
            {
                v.push_back(std::make_pair(newLower, nums[i] - 1));
                newLower = (long)nums[i] + 1;
            }
        }

        vector<string> res;
        for(const auto& item : v)
        {
            if(item.first == item.second)
            {
                res.push_back(std::to_string(item.first));
            }
            else
            {
                res.push_back(std::to_string(item.first) + "->" + std::to_string(item.second));
            }
        }

        if(newLower == newUpper)
        {
            res.push_back(std::to_string(newLower));
        }
        else if(newLower < newUpper)
        {
            res.push_back(std::to_string(newLower) + "->" + std::to_string(newUpper));
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{0, 1, 3, 50, 75};
    s.findMissingRanges(a, 0, 99);
}
