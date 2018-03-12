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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0) return res;

        std::sort(nums.begin(), nums.end());

        vector<pair<int, int>> dp(n); //length, last idx pair
        int maxLen = 1;
        int maxIdx = 0;

        for(int i = 0; i < n; ++i)
        {
            if(i == 0) dp[i] = std::make_pair(1, 0);
            int localMaxLen = 1;
            int localLastIdx = i;
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j].first + 1 > localMaxLen)
                    {
                        localMaxLen = dp[j].first + 1;
                        localLastIdx = j;
                    }
                }
            }
            dp[i] = std::make_pair(localMaxLen, localLastIdx);
            if(dp[i].first > maxLen)
            {
                maxLen = dp[i].first;
                maxIdx = i;
            }
        }

        while(true)
        {
            res.push_back(nums[maxIdx]);
            if(maxIdx == dp[maxIdx].second) break;
            maxIdx = dp[maxIdx].second;
        }

        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> a{1, 2, 3, 4, 12};
    const auto& r = s.largestDivisibleSubset(a);
    for(int i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
