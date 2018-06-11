#include "header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
            m[nums[i]] = i;

        vector<int> allRes(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; --i)
        {
            int t = -1;
            while(!s.empty())
            {
                if(nums[i] > s.top())
                    s.pop();
                else
                {
                    t = s.top();
                    break;
                }
            }
            s.push(nums[i]);
            allRes[i] = t;
        }

        vector<int> res;
        res.reserve(findNums.size());
        for(int i : findNums)
            res.push_back(allRes[m[i]]);
        return res;
    }
};

int main()
{
    Solution s;
}
