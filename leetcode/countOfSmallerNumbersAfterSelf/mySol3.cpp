#include "header.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        auto t = nums;
        sort(t.begin(), t.end());
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i) m[t[i]] = i;
        vector<int> bit(n + 1, 0);
        auto sum = [&](int idx) {
            int res = 0;
            while(idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };
        auto insert = [&](int idx) {
            while(idx <= n) {
                ++bit[idx];
                idx += idx & -idx;
            }
        };
        vector<int> res(n, 0);
        for(int i = n - 1; i >= 0; --i) {
            res[i] = sum(m[nums[i]]); // Trick here! Want to find # of elements less than itself
            insert(m[nums[i]] + 1);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}