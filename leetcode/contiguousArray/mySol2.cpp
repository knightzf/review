#include "header.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m{{0, -1}};
        int sum = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            if(m.count(sum)) res = max(res, i - m[sum]);
            else m[sum] = i;
        }
        return res;
    }
};

int main()
{
    Solution s;
}