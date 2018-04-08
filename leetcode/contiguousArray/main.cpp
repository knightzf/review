#include "header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int startIdx = -1;
        int res = 0;
        for(int i = 0; i < n;)
        {
            if(startIdx == -1 && (nums[i] == 0 || nums[i] == 1))
            {
                startIdx = i;
                unordered_map<int, int> m{{0, -1}};
                int val = 0;
                int j = startIdx;
                for(; j < n; ++j)
                {
                    if(nums[j] != 1 && nums[j] != 0)
                        break;
                    val += nums[j] == 1 ? 1 : -1;
                    if(m.find(val) == m.end())
                        m[val] = j;
                    else
                        res = max(res, j - m[val]);
                }

                i = startIdx = j;
            }
            else
            {
                ++i;
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{0, 1, 0};
    std::cout<<s.findMaxLength(a)<<std::endl;
}
