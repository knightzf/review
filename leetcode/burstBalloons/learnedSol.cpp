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
    int maxCoins(vector<int> &iNums) {
        int nums[iNums.size() + 2];
        int n = 1;
        for (int x : iNums) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;


        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left)
            {
                int right = left + k;
                for (int i = left + 1; i < right; ++i)
                {
                    std::cout<<left<<" "<<right<<" "<<i<<std::endl;
                    dp[left][right] = max(dp[left][right],
                         nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> a{3, 1, 5, 8};
    s.maxCoins(a);
}
