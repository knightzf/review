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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;

        for(int i = n - 1; i > 0; --i)
        {
            if(nums[i - 1] < nums[i])
            {
                for(int j = n - 1; j >= i; --j)
                {
                    if(nums[j] > nums[i - 1])
                    {
                        std::swap(nums[j], nums[i - 1]);
                        std::sort(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }

        std::reverse(nums.begin(), nums.end());
    }
};


int main() {
    Solution s;
    std::vector<int> a{1, 2, 3};
    s.nextPermutation(a);
    for(int i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
