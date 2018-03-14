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
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 0) return 0;

        int endIdx = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || nums[i] == nums[endIdx])
                ++cnt;
            else
                cnt = 1;

            if(cnt <= 2)
            {
                if(endIdx != i) std::swap(nums[endIdx], nums[i]);
                ++endIdx;
            }
        }

        return endIdx;
    }
};

int main() {
    Solution s;
    std::vector<int> a{1, 1, 1, 2, 2, 3};
    std::cout<<s.removeDuplicates(a)<<std::endl;
}
