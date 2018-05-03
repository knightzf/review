#include "header.h"

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i = 31; i >= 0; --i)
        {
            mask |= (1 << i);
            unordered_set<int> s;
            for(int num : nums)
                s.insert(num & mask);

            int tmp = max | (1 << i);
            for(int t : s)
            {
                if(s.find(tmp ^ t) != s.end())
                {
                    max = tmp;
                    break;
                }
            }
        }

        return max;
    }
};

int main()
{
    Solution s;
    vector<int> a{3, 10, 5, 25, 2, 8};
    s.findMaximumXOR(a);
}
