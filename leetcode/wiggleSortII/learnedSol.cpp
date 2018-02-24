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
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = *(nums.begin() + n / 2);

        int i = 0, left = 0, right = n - 1;
        while(i <= right)
        {
            if(nums[mapIndex(i, n)] > median)
            {
                std::swap(nums[mapIndex(i++, n)], nums[mapIndex(left++, n)]);
            }
            else if(nums[mapIndex(i, n)] < median)
            {
                std::swap(nums[mapIndex(i, n)], nums[mapIndex(right--, n)]);
            }
            else
            {
                ++i;
            }
        }
    }

    int mapIndex(int i, int n)
    {
        return (1 + 2 * i) % (n | 1);
    }
};

int main() {
    Solution s;
    vector<int> a{2,3,3,2,2,2,1,1};
    s.wiggleSort(a);
    for(int i : a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
