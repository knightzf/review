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
    int jump(vector<int>& nums)
    {
        if(nums.empty())
        {
            return 0;
        }

        int n = nums.size();

        std::vector<int> sum(n, -1);

        for(int i = 0; i < n; ++i)
        {
            sum[i] = i + nums[i];
        }

        /*for(auto i : sum)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        int result = 0;
        int target = n - 1;
        while(target != 0)
        {
            for(int i = 0; i < n; ++i)
            {
                if(sum[i] >= target)
                {
                    target = i;
                    ++result;
                    break;
                }
            }
        }

        return result;

    }
};

int main()
{
    Solution sol;
    std::vector<int> a{2, 3, 1, 1, 4};
    std::cout<<sol.jump(a)<<std::endl;
    return 0;
}
