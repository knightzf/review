#include "header.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, n = nums.size(), h = n;
        while(l < h) {
            int m = (l + h) / 2;
            if((m == 0 || nums[m] > nums[m - 1]) &&
               (m == n - 1 || nums[m] > nums[m + 1])) {
                   return m;
            }
            if(m != 0 && nums[m] < nums[m - 1]) h = m;
            else l = m + 1;
        }
        return -1;
    }
};

int main()
{
    //Solution s;    
}