#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double res = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        res = double(sum) / n;

        int len = n - 1;
        vector<int> v{sum};
        while(len >= k)
        {
            int removeIdx = n - len - 1;
            for(int i = 0, sz = v.size(); i < sz; ++i)
            {
                if(i == sz - 1)
                {
                    v.push_back(v[i] - nums[len]);
                    res = max(res, double(v[i + 1]) / len);
                }
                v[i] = v[i] - nums[removeIdx];
                res = max(res, double(v[i]) / len);
                --removeIdx;
            }
            for(int i : v)
                cout<<i<<" ";
            cout<<endl;
            --len;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> a{1,12,-5,-6,50,3};
    cout<<s.findMaxAverage(a, 4)<<endl;
}
