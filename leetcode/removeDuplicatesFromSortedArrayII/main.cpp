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

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 0)
        {
            return 0;
        }

        int currIdx = -1;
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || nums[i] != nums[currIdx])
            {
                count = 1;
                ++currIdx;
                if(currIdx != i)
                {
                    std::swap(nums[currIdx], nums[i]);
                }
            }
            else
            {
                if(nums[i] == nums[currIdx])
                {
                    if(count == 1)
                    {
                        count = 2;
                        ++currIdx;
                        if(currIdx != i)
                        {
                            std::swap(nums[currIdx], nums[i]);
                        }
                    }
                }
            }
        }

        /*for(int i = 0; i < currIdx + 1; ++i)
        {
            std::cout<<nums[i]<<" ";
        }
        std::cout<<std::endl;*/

        return currIdx + 1;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1, 1, 1, 2, 2, 3};
    std::cout<<sol.removeDuplicates(a)<<std::endl;
}
