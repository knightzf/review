#include "header.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int cnt = 0, res = 0;
        for(int i = 0, j = 0, n = s.size(); i < n; ++i) {
            ++m[s[i]];
            if(m[s[i]] == 1) ++cnt;
            if(cnt <= 2) {
                res = max(res, i - j + 1);
            } else {
                for(; j < i && cnt > 2; ++j) {
                    --m[s[j]];
                    if(m[s[j]] == 0) --cnt;
                }
            }
        }
        return res;
    }
};


int main()
{
    //Solution s;    
}