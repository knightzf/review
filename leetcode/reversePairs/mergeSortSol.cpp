#include "header.h"

class Solution {
private:
    int n;
    int res;
public:
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        res = 0;
        if(n > 0)
            impl(nums, 0, n - 1);
        /*for(int i : nums)
            cout<<i<<" ";
        cout<<endl;*/
        return res;
    }

    void impl(vector<int>& nums, int startIdx, int endIdx)
    {
        if(startIdx == endIdx) return;
        int midIdx = (startIdx + endIdx) / 2;
        impl(nums, startIdx, midIdx);
        impl(nums, midIdx + 1, endIdx);

        for(int i = startIdx; i <= midIdx; ++i)
        {
            binarySearch(nums, i, midIdx + 1, endIdx);
        }

        merge(nums, startIdx, endIdx);
    }

    void binarySearch(vector<int>& nums, int idx, int startIdx, int endIdx)
    {

        int target = nums[idx] % 2 == 0 ? ((nums[idx]) / 2) : ((nums[idx] + 1) / 2);
        /*cout<<"called "<<idx<<" "<<startIdx<<" "<<endIdx<<" "<<target<<endl;
        for(int i = startIdx; i <= endIdx; ++i)
            cout<<nums[i]<<" ";
        cout<<endl;*/
        if(nums[startIdx] >= target)
        {
            return;
        }
        else if(nums[endIdx] < target)
        {
            res += endIdx - startIdx + 1;
            return;
        }

        int i = startIdx, j = endIdx;
        while(i + 1 != j)
        {
            int midIdx = (i + j) / 2;
            if(nums[midIdx] >= target)
            {
                j = midIdx;
            }
            else if(nums[midIdx] < target)
            {
                i = midIdx;
            }
        }
        //cout<<"res "<<i<<" "<<idx<<endl;
        res += i - startIdx + 1;
    }

    void merge(vector<int>& nums, int startIdx, int endIdx)
    {
        int midIdx = (startIdx + endIdx) / 2;
        vector<int> t; t.reserve(endIdx - startIdx + 1);
        int i = startIdx, j = midIdx + 1;
        while(i <= midIdx || j <= endIdx)
        {
            if(i > midIdx)
            {
                t.emplace_back(nums[j++]);
                continue;
            }

            if(j > endIdx)
            {
                t.emplace_back(nums[i++]);
                continue;
            }

            if(nums[i] <= nums[j])
            {
                t.emplace_back(nums[i++]);
            }
            else
            {
                t.emplace_back(nums[j++]);
            }
        }

        for(int i = startIdx; i <= endIdx; ++i)
            nums[i] = t[i - startIdx];
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 3, 2, 3, 1};
    vector<int> a{2, 4, 3, 5, 1};
    cout<<s.reversePairs(a)<<endl;
}
