#include "header.h"

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        k = abs(k);

        for(int i = 0; i < n - 1; ++i)
        {
            if(nums[i] == 0 && nums[i + 1] == 0)
                return true;
        }

        if(k == 0) return false;

        vector<int> sum(n);
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            sum[i] = i == 0 ? nums[i] : (nums[i] + sum[i - 1]);
            if(m.find(sum[i]) == m.end())
                m[sum[i]] = i;
        }

        for(int i = 1; i < n; ++i)
        {
            int cnt = 0;
            while(sum[i] - k * cnt >= sum[0])
            {
                if(cnt == 0 && sum[i] % k == 0) return true;
                auto iter = m.find(sum[i] - k * cnt);
                if(iter != m.end() && iter->second < i)
                    return true;
                ++cnt;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    //vector<int> a{23,2,4,6,7};
    //std::cout<<s.checkSubarraySum(a, 0)<<std::endl;
    //vector<int> a{0, 0};
    //std::cout<<s.checkSubarraySum(a, -1)<<std::endl;
    //vector<int> a{1, 1};
    //std::cout<<s.checkSubarraySum(a, 2)<<std::endl;
    vector<int> a{1, 2, 3};
    std::cout<<s.checkSubarraySum(a, 4)<<std::endl;
}
