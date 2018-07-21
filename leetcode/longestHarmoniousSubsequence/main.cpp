#include "header.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num : nums)
            ++m[num];
        int res = 0;
        for(const auto& p : m)
        {
            if(m.count(p.first - 1))
            {
                res = max(res, m[p.first] + m[p.first - 1]);
            }

            if(m.count(p.first + 1))
            {
                res = max(res, m[p.first] + m[p.first + 1]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
