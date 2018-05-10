#include "header.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt(26, 0);
        for(char c : p)
        {
            ++cnt[c - 'a'];
        }

        int n = s.size();
        int m = p.size();
        vector<int> res;
        for(int i = 0; i < n; ++i)
        {
            if(cnt[s[i] - 'a'] && i + m <= n)
            {
                vector<int> cpy = cnt;
                bool match = true;
                int j = i;
                for(; j < i + m; ++j)
                {
                    --cpy[s[j] - 'a'];
                    if(cpy[s[j] - 'a'] < 0)
                    {
                        match = false;
                        if(cnt[s[j] - 'a'] == 0) i = j;
                        break;
                    }
                }

                if(match)
                    res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
}
