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
    vector<int> countSmaller(vector<int>& nums) {
        std::multiset<int> s;
        for(auto i : nums)
        {
            s.insert(i);
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto iter = s.lower_bound(nums[i]);
            int count = 0;
            for(auto j = s.begin(); j != iter; ++j)
            {
                ++count;
            }

            res.push_back(count);

            s.erase(iter);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{5,2,6,1};
    const auto& r = s.countSmaller(a);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
