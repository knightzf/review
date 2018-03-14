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
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        impl(nums, 0, n, res);
        return res;
    }

    void impl(vector<int>& nums, int startIdx, int endIdx, vector<vector<int>>& res)
    {
        if(startIdx == endIdx)
        {
            res.push_back({});
            return;
        }

        impl(nums, startIdx + 1, endIdx, res);

        int sz = res.size();
        for(int i = 0; i < sz; ++i)
        {
            auto t = res[i];
            t.push_back(nums[startIdx]);
            res.emplace_back(t);
        }
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2, 3};
    const auto& r = s.subsets(a);
    for(const auto& i : r)
    {
        for(int j : i)
        {
            std::cout<<j<<" ";
        }
        std::cout<<std::endl;
    }
}
