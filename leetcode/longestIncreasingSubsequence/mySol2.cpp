#include "header.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int num : nums) {
            auto iter = lower_bound(res.begin(), res.end(), num);
            if(iter == res.end()) res.push_back(num);
            else *iter = num;
        }
        return res.size();
    }
};

int main()
{
    //Solution s;
}