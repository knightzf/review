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
    void nextPermutation(vector<int>& nums)
    {
        int k = -1;
    	for (int i = nums.size() - 2; i >= 0; i--) {
    		if (nums[i] < nums[i + 1]) {
    			k = i;
    			break;
    		}
    	}
    	if (k == -1) {
    	    reverse(nums.begin(), nums.end());
    	    return;
    	}
    	int l = -1;
    	for (int i = nums.size() - 1; i > k; i--) {
    		if (nums[i] > nums[k]) {
    			l = i;
    			break;
    		}
    	}
    	swap(nums[k], nums[l]);
    	reverse(nums.begin() + k + 1, nums.end());
    }
};

int main()
{
    Solution sol;
    std::vector<int> a{1,2,3};
    sol.nextPermutation(a);
    for(auto& i: a)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
