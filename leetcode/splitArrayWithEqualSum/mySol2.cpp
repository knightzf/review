#include "header.h"

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        int sum[n + 1] = {0};
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        for(int i = 0; i < n; ++i) {
            if(i < 3 || i + 3 >= n) continue;
            unordered_set<int> s;
            for(int j = 1; j < i - 1; ++j) {
                if(sum[j] == sum[i] - sum[j + 1]) s.insert(sum[j]);
            }
            for(int j = i + 2; j < n - 1; ++j) {
                if(sum[j] - sum[i + 1] == sum[n] - sum[j + 1] && s.count(sum[j] - sum[i + 1])) return true;
            }
        }
        return false;
    }
};

int main()
{
    //Solution s;
}