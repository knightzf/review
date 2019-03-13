#include "header.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        int minNum = nums[0], maxNum = nums[0];
        for(int i = 0; i < n; ++i)
        {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }

        int avg = (maxNum - minNum) / (n - 1);
        vector<pair<int, int>> buckets(n - 1, {INT_MAX, INT_MIN});
        for(int i = 0; i < n; ++i)
        {
            int idx = ceil((nums[i] - minNum) / (avg + 1));
            buckets[idx].first = min(buckets[idx].first, nums[i]);
            buckets[idx].second = max(buckets[idx].second, nums[i]);
        }
        
        int res = 0;
        for(int i = 0; i < buckets.size(); ++i)
        {
            if(buckets[i].first == INT_MAX) continue;
            res = max(res, buckets[i].second - buckets[i].first);
            if(i != buckets.size() - 1)
            {
                int j = i + 1;
                for(; j < buckets.size() ; ++j)
                {
                    if(buckets[j].first != INT_MAX) break;
                }

                if(j < buckets.size() ) res = max(res, buckets[j].first - buckets[i].second);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{3, 6, 9, 1};
    cout<<s.maximumGap(a)<<endl;
}