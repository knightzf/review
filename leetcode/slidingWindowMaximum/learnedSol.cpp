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

        std::deque<int> q;
        vector<int> res;
        for(int i = 0; i < n; ++i)
        {
            while(!q.empty() && q.front() <= i - k) q.pop_front();

            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();

            q.push_back(i);

            if(i >= k - 1) res.push_back(nums[q.front()]);
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
