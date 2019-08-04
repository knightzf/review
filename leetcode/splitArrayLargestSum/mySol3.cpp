#include "header.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        long l = 0, h = sum;
        auto valid = [&](long x) {
            for(long i = 0, cnt = 1, sum = 0; i < n;) {
                if(nums[i] > x) return false;
                if(sum + nums[i] > x) {
                    ++cnt;
                    if(cnt > m) return false;
                    sum = 0;
                } else {
                    sum += nums[i];
                    ++i;
                }
            }
            return true;
        };

        while(l < h) {
            long t = l + (h - l) / 2;
            if(valid(t)) {
                h = t;
            } else {
                l = t + 1;
            }
        }
        return l;
    }
};

int main()
{
    Solution s;
}