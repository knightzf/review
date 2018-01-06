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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int r = nums[0];
        for(int i = 1, imin = r, imax = r; i < n; ++i)
        {
            if(nums[i] < 0)
            {
                std::swap(imin, imax);
            }

            imax = std::max(nums[i], imax * nums[i]);
            imin = std::min(nums[i], imin * nums[i]);

            std::cout<<nums[i]<<" "<<imax<<" "<<imin<<std::endl;
            r = std::max(r, imax);
        }

        return r;
    }
};


int main()
{
    Solution s;
    //vector<int> a{2,3,-2,4};
    vector<int> a{2, -5, -2, -4, 3};
    std::cout<<s.maxProduct(a)<<std::endl;
}
