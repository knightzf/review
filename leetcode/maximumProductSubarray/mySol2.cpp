#include "header.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int h = nums[0], l = h, res = l;
        for(int i = 1, n = nums.size(); i < n; ++i) {
            int a = h * nums[i];
            int b = l * nums[i];
            int c = nums[i];
            h = max(max(a, b), c);
            l = min(min(a, b), c);
            res = max(res, h);
        }
        return res;
    }
};

int main()
{
    //Solution s;    
}