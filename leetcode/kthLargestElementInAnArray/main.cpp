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
#include <iterator>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int rank = n - k + 1;
        int startIdx = 0;
        int endIdx = n;

        while(true)
        {
            int i = startIdx;
            int pivot = nums[endIdx - 1];

            for(int j = startIdx; j < endIdx; ++j)
            {
                if(nums[j] < pivot)
                {
                    std::swap(nums[j], nums[i]);
                    ++i;
                }
            }

            std::swap(nums[i], nums[endIdx - 1]);

            /*for(auto i : nums)
            {
                std::cout<<i<<" ";
            }
            std::cout<<std::endl;*/

            if(i - startIdx + 1 == rank)
            {
                return nums[i];
            }
            else if(i - startIdx + 1 > rank)
            {
                endIdx = i;
            }
            else if(i - startIdx + 1 < rank)
            {
                rank -= i - startIdx + 1;
                startIdx = i + 1;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> a{3, 2, 1, 5, 6, 4};
    std::cout<<s.findKthLargest(a, 2)<<std::endl;
}
