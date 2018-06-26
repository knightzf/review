#include "header.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;
        unordered_map<int, int> m;
        for(int i : nums)
            ++m[i];

        int res = 0;
        for(const auto& p : m)
        {
            if(k == 0)
            {
                res += (p.second > 1 ? 1 : 0);
            }
            else
            {
                if(m.count(p.first + k))
                {
                    ++res;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
