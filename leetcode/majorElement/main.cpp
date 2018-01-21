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
    int majorityElement(vector<int>& nums) {
        int major = nums[0]; int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(count == 0)
            {
                major = nums[i];
                ++count;
            }
            else if(nums[i] == major)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        return major;
    }
};

int main() {
    Solution s;
}
