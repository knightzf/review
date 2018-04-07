#include "header.h"

class Solution {
private:
    unordered_map<int, pair<int, int>> m;
public:
    Solution(const vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(m.find(nums[i]) == m.end())
            {
                m[nums[i]] = make_pair(1, i);
            }
            else
            {
                int totalCnt = m[nums[i]].first + 1;
                if(rand() % totalCnt == totalCnt - 1)
                {
                    m[nums[i]].second = i;
                }
                ++m[nums[i]].first;
            }
        }
    }

    int pick(int target) {
        return m[target].second;
    }
};


int main()
{
    //Solution s;
}
