#include "header.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n)
        {
            while(i < m && j < n && s[i] != t[j]) ++j;
            if(s[i] == t[j])
            {
                ++i;
                ++j;
            }
        }
        return i == m;
    }
};

int main()
{
    Solution s;
}
