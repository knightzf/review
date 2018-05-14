#include "header.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n == 0) return res;

        auto fixIdx = [&](int& idx, int& prevNum){
            if(nums[idx] != idx + 1)
            {
                if(prevNum == -1)
                {
                    prevNum = nums[idx];
                    idx = prevNum - 1;
                }
                else
                {
                    int t = nums[idx];
                    nums[idx] = prevNum;
                    prevNum = t;
                    idx = t - 1;
                }
            }
        };

        for(int i = 0; i < n; ++i)
        {
            int prevNum = -1;
            int idx = i;
            while(nums[idx] != idx + 1)
            {
                fixIdx(idx, prevNum);
            }

            /*for(int i = 0; i < n; ++i)
                cout<<nums[i]<<" ";
            cout<<endl;*/
        }

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i + 1)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{4,3,2,7,8,2,3,1};
    s.findDisappearedNumbers(a);
}
