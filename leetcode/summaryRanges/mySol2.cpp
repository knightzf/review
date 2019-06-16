#include "header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, end = 0;
        bool hasNumber = false;
        vector<string> res;
        for(int i = 0, n = nums.size(); i < n; ++i) {
            if(!hasNumber) {
                start = nums[i];
                end = nums[i];
                hasNumber = true;
            } else {
                if(nums[i] == end + 1) {
                    end = nums[i];
                } else {
                    string t = to_string(start);
                    if(end != start) t += "->" + to_string(end);
                    res.emplace_back(t);
                    hasNumber = false;
                    --i;
                }
            }
        }
        if(hasNumber) {
            string t = to_string(start);
            if(end != start) t += "->" + to_string(end);
            res.emplace_back(t);
        }
        return res;
    }
};

int main()
{
    Solution s;
}