#include "header.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k < 1 || t < 0) return false;
        int n = nums.size();

        vector<long> v; 
        v.reserve(n);
        for(int i : nums) v.push_back(long(i) - INT_MIN);
        
        long tt = t;
        unordered_map<long, long> m;
        for(int i = 0; i < n; ++i) {
            if(i > k) m.erase(v[i - k - 1] / (tt + 1));
            long bucket = v[i] / (tt + 1);
            if(m.count(bucket) || 
               (m.count(bucket - 1) && v[i] - m[bucket - 1] <= t) ||
               (m.count(bucket + 1) && m[bucket + 1] - v[i] <= t))
               return true;
            m[bucket] = v[i];
        }
        return false;
    }
};

int main()
{
    Solution s;
}