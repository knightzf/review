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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(max(nums[0], nums[1]), nums[2]);

        vector<int> dp1(n, 0);
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        dp1[2] = nums[0] + nums[2];

        vector<int> dp2(n, 0);
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = nums[2];

        int max1 = max(dp1[0], max(dp1[1], dp1[2]));
        int max2 = max(dp2[0], max(dp2[1], dp2[2]));

        for(int i = 3; i < n; ++i)
        {
            dp1[i] = nums[i] + max(dp1[i - 2], dp1[i - 1] - nums[i - 1]);
            max1 = max(max1, i != n - 1 ? dp1[i] : dp1[i] - nums[0]);
            dp2[i] = nums[i] + max(dp2[i - 2], dp2[i - 1] - nums[i - 1]);
            max2 = max(max2, dp2[i]);
        }

        /*for(auto i : dp1)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
        for(auto i : dp2)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        return max(max1, max2);
    }
};

int main() {
    Solution s;
    vector<int> a{2, 7, 9, 3, 1};
    std::cout<<s.rob(a)<<std::endl;
}
