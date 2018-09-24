#include "header.h"

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), total = n * (n - 1) / 2;
        int l = 0, r = nums.back() - nums[0];
        while(true)
        {
            int m = (l + r) / 2;            
            int cnt = 0;
            int equalCnt = 0;
            for(int i = 0; i < n - 1; ++i)
            {
                auto lowerIter = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + m);
                auto upperIter = upper_bound(nums.begin() + i + 1, nums.end(), nums[i] + m);
                if(lowerIter == nums.end()) break;
                int t = nums.end() - lowerIter;
                cnt += t;
                if(*lowerIter == nums[i] + m) equalCnt += upperIter - lowerIter;
            }

            if(cnt > total - k && equalCnt != 0 && total - cnt + equalCnt >= k) return m;
            if(cnt > total - k) l = m + 1;
            else r = m;
        }
    }
};

int main() {
    Solution s;
    /*vector<int> a{2,2,0,1,1,0,0,1,2,0};
    cout<<s.smallestDistancePair(a, 2)<<endl;
    //*/
    vector<int> a{38,33,57,65,13,2,86,75,4,56};
    cout<<s.smallestDistancePair(a, 26)<<endl;

    sort(a.begin(), a.end());
    vector<int> res;
    for(int i = 0, n = a.size(); i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            res.push_back(a[j] - a[i]);
        }
    }
    sort(res.begin(), res.end());
    for(int i : res)
        cout<< i << " ";
    cout<<endl;
}
