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
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, added = 0, i = 0;
        while(miss <= n)
        {
            if(i < nums.size() && miss >= nums[i])
            {
                miss += nums[i++];
            }
            else
            {
                ++added;
                miss += miss;
            }
        }

        return added;
    }
};


int main() {
    Solution s;
}
