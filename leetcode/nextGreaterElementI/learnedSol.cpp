#include "header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
            m[nums[i]] = i;

        vector<int> res(findNums.size());
        stack<int> s;
        int k = findNums.size() - 1;
        for(int i = n - 1; i >= 0 && k >= 0; --i)
        {
            int t = -1;
            while(!s.empty())
            {
                if(nums[i] > s.top())
                    s.pop();
                else
                    t = s.top();
            }
            s.push(nums[i]);

            if(m[findNums[k]] == i)
            {
                res[k] = t;
                --k;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
