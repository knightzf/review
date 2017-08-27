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

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(size_t i = 0, sz = nums.size() - 1; i < sz; ++i)
        {
            if(nums[i] > nums[i + 1])
            {
                ++count;

                if(i != 0)
                {
                    if(nums[i - 1] > nums[i + 1])
                    {
                        nums[i + 1] = nums [i];
                    }
                    else
                    {
                        nums[i] = nums[i - 1];
                    }
                }
            }

            if(count > 1)
                return false;
        }

        return true;
    }
};
int main()
{
    Solution sol;
    //std::vector<int> a{3, 4, 2, 3};
    std::vector<int> a{2, 3, 3, 2, 4};
    std::cout<<sol.checkPossibility(a)<<std::endl;
    //std::cout<<sol.generateParenthesis(3)<<std::endl;
    return 0;
}
