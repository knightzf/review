#include "header.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(32, 0);
        for(int num : nums) {
            int i = 0;
            while(num) {
                if(num & 1) ++v[i];
                num >>= 1;
                ++i;
            }
        }
        int res = 0;
        for(int num : nums) {
            for(int i = 0; i < 32; ++i) {
                if(num & (1 << i)) res += (n - v[i]);
                else res += v[i];
            }
        }
        return res / 2;
    }
};

int main()
{
    //Solution s;
}