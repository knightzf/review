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
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < n - 2; ++i)
        {
            int left = i + 1, right = n - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] < target)
                {
                    ++res;
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }

        return res;
    }
};


int main() {
    Solution s;

    {
        vector<int> a{-1,-5,14,-6,0,10,2,-12,-6,13,6,6,4,-10,7,-2,8,-15,-13,14,2,3,12,14,8,-12,3,1,12,7,-5,0,-14,4,-6,-5,-9,-4,-3,-5,-15,-15,2,9,8,-1,-4,5,1,-7,-5,1,14,-2,-8,-4,5,9,11,11,-9,-12,14,8,4,2,-8,-15,-6,0,-15,7,8,-8,8,14,-1,-14,-11,10,1,10,11,14,1,-2,6,-6,-6,7,-7,3,-15,-11,-4,-8,12,-2,-1,-1,9,1,-6,-1,11,-4,2,7,-2};
        std::cout<<s.threeSumSmaller(a, 8)<<std::endl;
    }
    {
        vector<int> a{0,-4,-1,1,-1,2};
        std::cout<<s.threeSumSmaller(a, -5)<<std::endl;
    }
    {
        vector<int> a{3, 1, 0, -2};
        std::cout<<s.threeSumSmaller(a, 4)<<std::endl;
    }
    {
        vector<int> a{1, 0, -1};
        std::cout<<s.threeSumSmaller(a, 0)<<std::endl;
    }

    {
        vector<int> a{-2, 0, 1, 3};
        std::cout<<s.threeSumSmaller(a, 2)<<std::endl;
    }
    {
        vector<int> a{1, 1, -2};
        std::cout<<s.threeSumSmaller(a, 1)<<std::endl;
    }
}
