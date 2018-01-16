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

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];

        for(int i = 2; i < n; ++i)
        {
            dp[i] = nums[i] + max( + dp[i - 2], dp[i - 1] - nums[i - 1]);
        }

        return max(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution s;
    vector<int> a{2, 1, 1, 2};
    std::cout<<s.rob(a)<<std::endl;
}
