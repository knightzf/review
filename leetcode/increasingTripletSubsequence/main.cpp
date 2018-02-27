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
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int temp[3];
        int j = 0;
        temp[0] = nums[0];

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] > temp[j])
            {
                temp[++j] = nums[i];
            }
            else if(nums[i] < temp[j])
            {
                int k = i + 1;
                while(k < n && nums[k] == nums[i]) ++k;
                --k;
                i = k;
                if(n - i >= 3 && nums[i] < temp[0])
                {
                    j = 0;
                    temp[j] = nums[i];
                }
                else if(n - i >=2 && nums[i] > temp[0])
                {
                    j = 1;
                    temp[j] = nums[i];
                }
            }

            if(j == 2)
            {
                return true;
            }
        }

        return false;
    }
};


int main() {
    Solution s;
    //vector<int> a{1, 2, 3, 4, 5};
    //vector<int> a{5, 4, 3, 2, 1};
    //vector<int> a{0, 2, -1, -1, -1, 3};
    vector<int> a{1, 0, 0, 0, -1, 0, 0, 0, 3};
    std::cout<<s.increasingTriplet(a)<<std::endl;
}
