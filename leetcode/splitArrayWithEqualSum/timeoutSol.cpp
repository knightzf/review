#include "header.h"

class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, set<int>> m;
        vector<int> sum(nums.size(), 0);
        for(int i = 0; i < n; ++i)
        {
            sum[i] = i == 0 ? nums[i] : (sum[i - 1] + nums[i]);
            m[sum[i]].insert(i);
        }

        for(int i = 1; i <= n - 6; ++i)
        {
            int t = sum[i - 1];
            for(auto iter = m[sum[i] + t].upper_bound(i); iter != m[sum[i] + t].end(); ++iter)
            {
                int j = *iter + 1;
                for(auto jter = m[sum[j] + t].upper_bound(j); jter != m[sum[j] + t].end(); ++jter)
                {
                    int k = *jter + 1;
                    if(sum[n - 1] - sum[k] == t) return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,1,2,1,2,1};
    cout<<s.splitArray(a)<<endl;
}
