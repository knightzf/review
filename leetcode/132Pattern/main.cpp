#include "header.h"

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int maxS3 = INT_MIN;
        for(int i = n - 1; i >= 0; --i)
        {
            int num = nums[i];
            if(num < maxS3) return true;
            if(s.empty() || num <= s.top()) s.push(num);
            else
            {
                while(!s.empty() && s.top() < num)
                {
                    maxS3 = max(maxS3, s.top());
                    s.pop();
                }
                s.push(num);
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 3, -2, -1};
    //vector<int> a{1, 3, 0, 2};
    vector<int> a{1,3,-1,8,-7,-3,6};
    //vector<int> a{1,0,1,-4,-3};
    std::cout<<s.find132pattern(a)<<std::endl;
}
