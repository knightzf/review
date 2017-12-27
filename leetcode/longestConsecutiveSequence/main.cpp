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

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int maxLen = 0;

        std::unordered_set<int> numSet(nums.begin(), nums.end());

        for(auto num : numSet)
        {
            if(numSet.find(num - 1) == numSet.end())
            {
                int y = num + 1;
                while(numSet.find(y) != numSet.end())
                {
                    ++y;
                }
                maxLen = std::max(maxLen, y - num);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
}
