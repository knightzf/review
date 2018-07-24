#include "header.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] == 0) continue;
            int endIdx = -1;
            for(int j = i + 1; j < n; ++j)
            {
                if(endIdx == -1)
                {
                    auto iter = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
                    endIdx = j + distance(nums.begin() + j, iter);
                }
                else
                {
                    while(endIdx < n && nums[endIdx] < nums[i] + nums[j]) ++endIdx;
                }

                //cout<<i<<" "<<j<<" "<<endIdx<<endl;
                res += endIdx - j - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1,1,3,4};
    cout<<s.triangleNumber(a)<<endl;
}
