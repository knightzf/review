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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        res[0] = 1;

        for(int i = 1; i < n; ++i)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int right = 1;
        for(int i = n -1; i >= 0; --i)
        {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};

int main() {
    Solution s;
}
