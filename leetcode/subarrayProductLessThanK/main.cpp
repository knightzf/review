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

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int n = nums.size();
        std::vector<int> countV(n, 0);

        for(int i = 0; i < n; ++i)
        {
            int count = 0;
            int t = nums[i];

            if(t == 1)
            {
                if(i != 0 && nums[i - 1] == 1)
                {
                    countV[i] = countV[i - 1] > 0 ? countV[i - 1] - 1 : 0;
                    continue;
                }
            }

            int j = i;
            while(t < k)
            {
                ++count;
                if(++j < n)
                {
                    while(nums[j] == 1 && j < n - 1)
                    {
                        ++count;
                        ++j;
                    }

                    t *= nums[j];
                }
                else
                {
                    break;
                }
            }

            countV[i] = count;
        }

        int r = 0;
        for(int i : countV)
        {
            r += i;
        }

        return r;
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{10, 5, 2, 6};
    std::cout<<sol.numSubarrayProductLessThanK(a, 100)<<std::endl;
}
