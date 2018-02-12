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
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int maxLen = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxLen = max(maxLen, dp[i]);
        }


        return maxLen;
    }
};

int main() {
    Solution s;
    //vector<int> a{10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> a{1, 3, 6, 7, 9, 4, 10, 5, 6};
    std::cout<<s.lengthOfLIS(a)<<std::endl;
}
