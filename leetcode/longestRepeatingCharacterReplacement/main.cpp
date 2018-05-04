#include "header.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int startIdx = 0;
        int maxLen = 0;
        int maxUnchangedCharCnt = 0;
        vector<int> charCnt(26, 0);

        for(int endIdx = 0; endIdx < n; ++endIdx)
        {
            maxUnchangedCharCnt = max(maxUnchangedCharCnt, ++charCnt[s[endIdx] - 'A']);
            while(endIdx - startIdx + 1 - maxUnchangedCharCnt > k)
            {
                --charCnt[s[startIdx] - 'A'];
                ++startIdx;
            }
            maxLen = max(maxLen, endIdx - startIdx + 1);
        }
        return maxLen;
    }
};

int main()
{
    Solution s;
}
