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
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n == 0) return res;
        if(n == 1)
        {
            res.push_back(std::to_string(nums[0]));
            return res;
        }

        int start = nums[0];
        for(int i = 1; i < n; ++i)
        {
            if(nums[i] != nums[i - 1] + 1)
            {
                if(start != nums[i - 1])
                {
                    res.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
                }
                else
                {
                    res.push_back(std::to_string(start));
                }

                start = nums[i];
            }

            if(i == n - 1)
            {
                if(start != nums[i])
                {
                    res.push_back(std::to_string(start) + "->" + std::to_string(nums[i]));
                }
                else
                {
                    res.push_back(std::to_string(start));
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    //vector<int> a{0, 1, 2, 4, 5, 7};
    vector<int> a{0, 2, 3, 4, 6, 8, 9};
    const auto& i = s.summaryRanges(a);
    for(auto j : i)
    {
        std::cout<<j<<std::endl;
    }
}
