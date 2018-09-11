#include "header.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        int avg = sum / k;

        for(int i = 0, n = nums.size(); i < n; ++i)
        {
            if(nums[i] != INT_MAX) {                
                int t = nums[i];
                nums[i] = INT_MAX;
                
                if(t > avg) return false;
                else if(t == avg) continue;

                if(!impl(nums, avg - t)) return false;
            }
        }
        return true;
    }

    bool impl(vector<int>& nums, int sum)
    {
        for(int i = 0, n = nums.size(); i < n; ++i)
        {
            if(nums[i] <= sum) {
                int t = nums[i];
                nums[i] = INT_MAX;
                if(t == sum) return true;
                if(impl(nums, sum - t)) return true;
                nums[i] = t;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    //vector<int> a{7628,3147,7137,2578,7742,2746,4264,7704,9532,9679,8963,3223,2133,7792,5911,3979};
    //cout<<s.canPartitionKSubsets(a, 6)<<endl;
    vector<int> a{4,3,2,3,5,2,1};
    cout<<s.canPartitionKSubsets(a, 4)<<endl;
}
