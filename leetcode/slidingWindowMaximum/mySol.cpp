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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return vector<int>();

        std::multiset<int> s;

        for(int i = 0; i < k; ++i)
        {
            s.insert(nums[i]);
        }

        vector<int> res;
        res.push_back(*s.rbegin());

        for(int i = k ; i < n; ++i)
        {
            int a = nums[i - k];
            s.erase(s.find(a));
            s.insert(nums[i]);
            res.push_back(*s.rbegin());
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1,3,-1,-3,5,3,6,7};
    const auto& r = s.maxSlidingWindow(a, 3);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
