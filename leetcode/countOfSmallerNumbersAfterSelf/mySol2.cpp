#include "header.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> t;
        for(int i = n - 1; i >= 0; --i) {
            auto iter = lower_bound(t.begin(), t.end(), nums[i]);
            res[i] = distance(t.begin(), iter);
            t.insert(iter, nums[i]);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}