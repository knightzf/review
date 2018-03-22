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
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;

        int firstZeroIdx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != 0)
            {
                while(nums[firstZeroIdx] != 0 && firstZeroIdx < n) ++firstZeroIdx;
                if(firstZeroIdx > n) break;
                std::swap(nums[i], nums[firstZeroIdx++]);
            }
        }
    }
};
int main() {
    Solution s;
}
