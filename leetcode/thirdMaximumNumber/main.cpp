#include "header.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        for(int j = 0; j < 3; ++j)
        {
            int m = INT_MIN;
            bool found = false;
            for(int i = 0; i < n; ++i)
            {
                if(!v.empty() && (nums[i] == v.back() || nums[i] == v[0]))
                {
                    continue;
                }

                m = max(m, nums[i]);
                found = true;
            }
            if(found)
                v.push_back(m);
            else
                break;
        }

        return v.size() == 3 ? v.back() : v[0];
    }
};

int main()
{
    Solution s;
    vector<int> a{2, 2, 3, 1};
    std::cout<<s.thirdMax(a)<<std::endl;
}
