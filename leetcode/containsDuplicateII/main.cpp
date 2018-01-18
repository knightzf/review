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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> numIdx;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(numIdx.find(nums[i]) != numIdx.end())
            {
               if(i - numIdx[nums[i]] <= k)
                {
                    return true;
                }
            }

            numIdx[nums[i]] = i;
        }

        return false;
    }
};

int main() {
    Solution s;
}
