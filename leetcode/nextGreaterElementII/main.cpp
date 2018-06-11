#include "header.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        vector<int> duplicate = nums;
        duplicate.insert(duplicate.end(), nums.begin(), nums.end());
        duplicate.pop_back();

        vector<int> res(n);
        stack<int> s;
        for(int i = 2 * n - 2; i >= 0; --i)
        {
            int t = -1;
            while(!s.empty())
            {
                if(duplicate[i] >= s.top())
                    s.pop();
                else
                {
                    t = s.top();
                    break;
                }
            }
            s.push(duplicate[i]);

            if(i <= n - 1)
                res[i] = t;
        }

        return res;
    }
};

int main()
{
    Solution s;
}
