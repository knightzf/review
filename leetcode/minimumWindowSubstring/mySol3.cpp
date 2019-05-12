#include "header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        unordered_map<char, int> need;
        for(char c : t) ++need[c];
        int needCnt = n;
        unordered_map<char, int> have;
        string res;
        for(int i = 0, startIdx = 0; i < m; ++i)
        {
            char c = s[i];
            ++have[c];
            if(have[c] <= need[c]) --needCnt;
            while(needCnt == 0)
            {
                if(res.empty() || i - startIdx + 1 < res.size())
                    res = s.substr(startIdx, i - startIdx + 1);
                char c = s[startIdx];
                --have[c];
                if(have[c] < need[c]) ++needCnt;
                ++startIdx;
            }
        }
        return res;
    }
};


int main()
{
    Solution s;
}