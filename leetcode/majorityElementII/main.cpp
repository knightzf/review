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
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<int>();

        int major1 = nums[0], major2 = nums[0];
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == major1)
            {
                ++count1;
            }
            else if(nums[i] == major2)
            {
                ++count2;
            }
            else if(count1 == 0)
            {
                major1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                major2 = nums[i];
                count2 = 1;
            }
            else
            {
                --count1;
                --count2;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == major1) ++count1;
            else if(nums[i] == major2) ++count2;
        }

        vector<int> res;
        if(count1 > n / 3) res.push_back(major1);
        if(count2 > n / 3) res.push_back(major2);

        return res;
    }
};

int main() {
    Solution s;
}
