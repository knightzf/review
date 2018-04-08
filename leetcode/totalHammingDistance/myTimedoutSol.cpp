#include "header.h"

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                int t = nums[i] ^ nums[j];
                if(m.find(t) == m.end())
                {
                    m[t] = hammingDistance(t);
                }
                res += m[t];
            }
        }
        return res;
    }

    int hammingDistance(int r) {
        int res = 0;
        while(r)
        {
            if(r & 1) ++res;
            r >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
