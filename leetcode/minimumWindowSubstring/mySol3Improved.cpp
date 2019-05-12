#include "header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> need(128,0);
        for(char c : t) ++need[c];
        int needCnt = n;
        vector<int> have(128,0);
        int idx = 0;
        int minLen = m + 1;
        string res;
        for(int i = 0, startIdx = 0; i < m; ++i)
        {
            char c = s[i];
            ++have[c];
            if(have[c] <= need[c]) --needCnt;
            while(needCnt == 0)
            {
                if(i - startIdx + 1 < minLen)
                {
                    idx = startIdx;
                    minLen = i - startIdx + 1;
                }
                char c = s[startIdx];
                --have[c];
                if(have[c] < need[c]) ++needCnt;
                ++startIdx;
            }
        }
        return minLen == m + 1 ? "" : s.substr(idx, minLen);
    }
};


int main()
{
    Solution s;
}