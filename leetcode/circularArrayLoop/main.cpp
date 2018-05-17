#include "header.h"

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != 0)
            {
                int steps = impl(nums, i, n, nums[i] > 0);
                //std::cout<<i<<" "<<steps<<endl;
                if(steps > 1) return true;
            }
        }
        return false;
    }

    int impl(vector<int>& nums, int idx, int n, bool right)
    {
        if(nums[idx] == 0) return 0;

        if((nums[idx] > 0) != right) return -1;

        int nextIdx = next(idx, nums[idx], n);
        if(nextIdx == idx) return -1;
        //std::cout<<"idx "<<idx<<" "<<nextIdx<<std::endl;

        nums[idx] = 0;
        int steps = impl(nums, nextIdx, n, right);
        if(steps >= 0)
            return steps + 1;
        else
            return -1;
    }

    int next(int idx, int steps, int n)
    {
        if(steps < 0)
        {
            steps = n - (-steps) % n;
        }

        idx += steps;
        return idx % n;
    }
};

int main()
{
    Solution s;
    //vector<int> a{2, -1, 1, 2, 2};
    //vector<int> a{-1, 2};
    vector<int> a{-1, -2, -3, -4, -5};
    std::cout<<s.circularArrayLoop(a)<<std::endl;
}
