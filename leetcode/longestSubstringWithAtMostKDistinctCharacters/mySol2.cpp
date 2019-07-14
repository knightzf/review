#include "header.h"

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt = 0, res = 0;
        unordered_map<char, int> v;
        for(int startIdx = 0, i = 0, n = s.size(); i < n; ++i) {
            ++v[s[i]];
            if(v[s[i]] == 1) ++cnt;
            if(cnt <= k) res = max(res, i - startIdx + 1);
            else {
                while(cnt > k) {
                    --v[s[startIdx]];
                    if(v[s[startIdx]] == 0) --cnt;
                    ++startIdx;
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