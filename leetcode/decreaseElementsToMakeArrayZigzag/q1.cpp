#include "header.h"

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        auto f = [&](bool flag) {
            int res = 0;
            for(int i = (flag ? 1 : 0), n = nums.size(); i < n; i += 2) {
                int left = i == 0 ? 0 : (nums[i] >= nums[i - 1] ? nums[i] - nums[i - 1] + 1: 0);
                int right = i == n - 1 ? 0 : (nums[i] >= nums[i + 1] ? nums[i] - nums[i + 1] + 1 : 0);
                res += max(left, right);
            }
            return res;
        };
        int a = f(true), b = f(false);
        return min(a, b);
    }
};

int main()
{
    Solution s;
    vector<int> a{2,7,10,9,8,9};
    cout<<s.movesToMakeZigzag(a)<<endl;
    vector<int> b{{10,4,4,10,10,6,2,3}};
    cout<<s.movesToMakeZigzag(b)<<endl;
}
