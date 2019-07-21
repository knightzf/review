#include "header.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n;
        while(l < h) {
            int m = (l + h) / 2;
            int next = m;
            if(m > 0 && nums[m - 1]) next = m - 1;
            if(m < n - 1 && nums[m + 1]) next = m + 1;
            if(next == m) return nums[m];
            int t = min(m, next);
            if(t & 1) h = m;
            else l = max(m, next) + 1;
        }
        return -1;
    }
};

int main()
{
    //Solution s;
}