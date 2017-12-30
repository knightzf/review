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
    vector<int> singleNumber(vector<int>& nums)
    {
        int totalxor = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            totalxor ^= nums[i];
        }

        int bitmap = 1;
        while((totalxor & bitmap) == 0)
        {
            bitmap <<= 1;
        }

        int num1 = 0;
        int num2 = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] & bitmap == 1)
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }

        vector<int> res{num1, num2};
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,1,3,2,5};
    s.singleNumber(a);
}
