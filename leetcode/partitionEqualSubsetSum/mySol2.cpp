#include "header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        unordered_set<int> s;
        for(int num : nums) {
            unordered_set<int> t{num};
            for(int i : s) {
                t.insert(i + num);
            }
            for(int i : t) {
                if( i == sum / 2) return true;
                s.insert(i);
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
}