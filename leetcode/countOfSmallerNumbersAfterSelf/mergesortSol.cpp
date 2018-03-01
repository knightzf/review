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
        int n = nums.size();
        vector<int> res(n, 0);

        vector<int> idx(n, 0);
        for(int i = 0; i < n; ++i)
        {
            idx[i] = i;
        }

        impl(nums, idx, 0, n - 1, res);
        return res;
    }

    void impl(vector<int>& nums, vector<int>& idx, int startIdx, int endIdx, vector<int>& res)
    {
        if(startIdx >= endIdx) return;

        int midIdx = (startIdx + endIdx) / 2;

        impl(nums, idx, startIdx, midIdx, res);
        impl(nums, idx, midIdx + 1, endIdx, res);

        vector<int> temp(endIdx - startIdx + 1);
        int i = startIdx, j = midIdx + 1, t = midIdx + 1;
        int k = 0;
        for(; i <= midIdx; ++i, ++k)
        {
            while(j <= endIdx && nums[idx[j]] < nums[idx[i]]) ++j;
            res[idx[i]] += j - midIdx -1;
            while(t <= endIdx && nums[idx[t]] < nums[idx[i]]) temp[k++] = idx[t++];
            temp[k] = idx[i];
        }
        for(int i = 0; i < t - startIdx; ++i)
        {
            idx[startIdx + i] = temp[i];
        }
    }
};



int main() {
    Solution s;
    vector<int> a{5, 2, 6, 1};
    const auto& r = s.countSmaller(a);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
