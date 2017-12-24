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
    int dominantIndex(vector<int>& nums)
    {
        if(nums.empty())
        {
            return -1;
        }

        if(nums.size() == 1)
        {
            return 0;
        }

        int first, firstIdx, second;

        if(nums[0] > nums[1])
        {
            first = nums[0];
            firstIdx = 0;
            second = nums[1];
        }
        else
        {
            first = nums[1];
            firstIdx = 1;
            second = nums[0];
        }

        int sz = nums.size();

        for(int i = 2; i < sz; ++i)
        {
            if(nums[i] > first)
            {
                second = first;

                first = nums[i];
                firstIdx = i;
            }
            else if(nums[i] > second)
            {
                second = nums[i];
            }
        }

        return first >= 2 * second ? firstIdx : -1;
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 0, 0, 0};
    vector<int> b{0, 0, 2, 3};
    vector<int> c{0, 0, 3, 2};
    std::cout<<s.dominantIndex(a)<<std::endl;
    std::cout<<s.dominantIndex(b)<<std::endl;
    std::cout<<s.dominantIndex(c)<<std::endl;
}
