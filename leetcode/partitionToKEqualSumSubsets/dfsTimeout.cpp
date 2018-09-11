#include "header.h"

class Solution {
private:
    set<vector<int>> s;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        s.clear();
        int sum = 0;
        int maxNum = 0;
        for(int num : nums)
        {
            sum += num;
            maxNum = max(maxNum, num);
        }

        if(sum % k != 0) return false;
        if(maxNum > sum / k) return false;

        vector<int> v(k, 0);
        return dfs(nums, v, sum / k, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& v, int avg, int idx)
    {
        if(idx == nums.size()) return true;
        if(s.count(v)) return false;

        for(int i = 0, n = v.size(); i < n; ++i) {
            if(v[i] + nums[idx] <= avg)
            {
                v[i] += nums[idx];
                if(dfs(nums, v, avg, idx + 1)) return true;
                v[i] -= nums[idx];
            }
        }

        s.insert(v);
        return false;
    }
};

int main() {
    Solution s;
    vector<int> a{7628,3147,7137,2578,7742,2746,4264,7704,9532,9679,8963,3223,2133,7792,5911,3979};
    cout<<s.canPartitionKSubsets(a, 6)<<endl;
}
