#include "header.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int val = 1, lastCnt = 1;
        for(int i = 0; i < n; ++i)
        {
            int j = i + (lastCnt > 0 ? lastCnt - 1 : 0);
            while(j < n) {
                if(val * nums[j] < k) {
                    val *= nums[j];
                    ++j;
                }
                else break;
            }
            
            lastCnt = j - i;                        
            res += lastCnt;

            if(lastCnt < 1) {
                val = 1;
            }
            else {
                val /= nums[i];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
