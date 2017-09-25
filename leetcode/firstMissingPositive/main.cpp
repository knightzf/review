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

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            int k = nums[i];
            int count = 0;
            while(k > 0 && k <= n && k != i + 1 && k != nums[k - 1])
            {
                std::swap(nums[i], nums[k - 1]);

                k = nums[i];
            }
        }


        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{3,-1,23,7,21,12,8,9,18,21,-1,16,1,13,-3,22,23,13,7,14,3,6,4,-3};
    std::vector<int> a{0, 1, 2};
    std::cout<<sol.firstMissingPositive(a)<<std::endl;

    return 0;
}
