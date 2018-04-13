#include "header.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        std::map<int, vector<pair<int, int>>> m; // maxLen -> count
        int n = nums.size();
        vector<int> s;
        vector<int> v(n, 0);
        for(int i = 0; i < n; ++i)
        {
            int maxLen = 0;
            if(s.empty() || nums[i] > s.back())
            {
                s.push_back(nums[i]);
                maxLen = s.size();
            }
            else
            {
                for(int j = s.size() - 1; j >= 0; --j)
                {
                    if(nums[i] <= s[j] && (j == 0 || s[j - 1] < nums[i]))
                    {
                        s[j] = nums[i];
                        maxLen = j + 1;
                        break;
                    }
                }
            }

            int cnt = 0;
            if(maxLen == 1)
            {
                cnt = 1;
            }
            else
            {
                for(const auto& p : m[maxLen - 1])
                {
                    if(nums[p.first] < nums[i])
                        cnt += p.second;
                }
            }

            v[i] = cnt;

            //std::cout<<i<<" "<<maxLen<<" "<<cnt<<std::endl;

            m[maxLen].push_back(make_pair(i, cnt));
        }

        int res = 0;
        for(const auto& p: m.rbegin()->second)
            res += p.second;
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{84,-48,-33,-34,-52,72,75,-12,72,-45};
    vector<int> a{2,2,2,2,2};
    std::cout<<s.findNumberOfLIS(a)<<std::endl;
}
