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

class NumArray {
private:
    int n;
    vector<int> dp;
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        dp = vector<int>(n, 0);
        for(int i = 0; i < n; ++i)
        {
            dp[i] = (i == 0 ? nums[0] : dp[i - 1] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};
int main() {
    //Solution s;
}
