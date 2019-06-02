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
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<int> sums(n + 1, 0);
        vector<int> dp(n + 1, 0);

        int minLen = INT_MAX;

        for(int i = 1; i <= nums.size(); ++i)
        {
            if(dp[i - 1] == 0)
            {
                sums[i] = sums[i - 1] + nums[i - 1];
                if(sums[i] >= s)
                {
                    int sum = sums[i];
                    int len = i;
                    for(int j = 0; j < i; ++j)
                    {
                        if(sum - nums[j] >= s)
                        {
                            sum -= nums[j];
                            --len;
                        }
                        else
                        {
                            break;
                        }
                    }
                    sums[i] = sum;
                    dp[i] = len;
                }
                else
                {
                    dp[i] = 0;
                }
            }
            else
            {
                int len = dp[i - 1] + 1;
                int sum = sums[i - 1] + nums[i - 1];
                for(int j = i - len; j < i; ++j)
                {
                    //std::cout<<"nums "<<nums[j]<<std::endl;
                    if(sum - nums[j] >= s)
                    {
                        sum -= nums[j];
                        --len;
                    }
                    else
                    {
                        break;
                    }
                }

                sums[i] = sum;
                dp[i] = len;
            }

            //std::cout<<dp[i]<<std::endl;

            if(dp[i])
            {
                minLen = std::min(minLen, dp[i]);
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution s;
    //vector<int> a{2,3,1,2,4,3};
    vector<int> a{1,2,3,4,5};
    std::cout<<s.minSubArrayLen(11, a)<<std::endl;
}
