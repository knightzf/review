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
        int minLen = INT_MAX;
        long tempSum = 0;
        int endIdx = 0;
        for(int i = 0; i < n; ++i)
        {
            while(tempSum < s && endIdx < n) tempSum += nums[endIdx++];
            if(tempSum >= s)
            {
                minLen = min(minLen, endIdx - i);
                if(minLen == 1) return 1;
                tempSum -= nums[i];
            }
            else
                break;
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    //Solution s;
}
