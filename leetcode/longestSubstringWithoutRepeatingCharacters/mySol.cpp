#include "header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dup;
        int startIdx = 0;
        int res = 0;
        for(size_t i = 0, n = s.size(); i < n; ++i)
        {
            while(dup.count(s[i]))
            {
                dup.erase(s[startIdx]);
                ++startIdx;
            }
            dup.insert(s[i]);

            res = max(res, int(i - startIdx) + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
}