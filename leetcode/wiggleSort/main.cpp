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
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i)
        {
            if(i % 2 == 0)
            {
                if(nums[i] > nums[i + 1]) std::swap(nums[i], nums[i + 1]);
            }
            else
            {
                if(nums[i] < nums[i + 1]) std::swap(nums[i], nums[i + 1]);
            }
        }
    }
};

int main() {
    Solution s;
}
