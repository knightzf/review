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
        for(int i = 0; i < n; i += 2)
        {
            if(i + 1 < n && nums[i] >= nums[i + 1])
            {
                if(nums[i] > nums[i + 1]) std::swap(nums[i], nums[i + 1]);
                else {
                    bool fixed = false;
                    for(int j = i + 2; j < n; ++j)
                    {
                        if(nums[j] > nums[i])
                        {
                            std::swap(nums[i + 1], nums[j]);
                            fixed = true;
                            break;
                        }
                        else if(nums[j] < nums[i])
                        {
                            std::swap(nums[i], nums[j]);
                            fixed = true;
                            break;
                        }
                    }

                    if(!fixed)
                    {
                        for(int j = i - 1; j >= 0; --j)
                        {
                            if(j % 2 == 1 && nums[j] < nums[i])
                            {
                                std::swap(nums[j], nums[i]);
                                break;
                            }
                            else if(j % 2 == 0 && nums[j] != nums[i])
                            {
                                if(nums[j] > nums[i])
                                {
                                    std::swap(nums[j], nums[i + 1]);
                                }
                                else
                                {
                                    std::swap(nums[j], nums[i]);
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int i = 1; i < n; i += 2)
        {
            if(i + 1 < n)
            {
                if(nums[i] == nums[i + 1])
                {
                    if(i + 2 < n)
                    {
                        std::swap(nums[i - 1], nums[i + 1]);
                        std::swap(nums[i], nums[i + 2]);
                    }
                    else
                    {

                    }
                }
                else if(nums[i] < nums[i + 1])
                {
                    std::swap(nums[i], nums[i + 1]);
                }
            }
        }
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
