#include "header.h"

class Solution {
private:
    int res;
public:
    int longestSubstring(string s, int k) {
        res = 0;
        impl(s, 0, s.size(), k);
        return res;
    }

    void impl(const std::string& s, int startIdx, int endIdx, int k)
    {
        vector<int> cnt(26, 0);
        for(int i = startIdx; i < endIdx; ++i)
        {
            ++cnt[s[i] - 'a'];
        }

        bool found = true;
        for(int i = 0; i < 26; ++i)
        {
            if(cnt[i] != 0 && cnt[i] < k)
                found = false;
        }
        if(found)
        {
            res = max(res, endIdx - startIdx);
            return;
        }

        for(int i = startIdx; i < endIdx; ++i)
        {
            if(startIdx == -1 && cnt[s[i] - 'a'] >= k)
            {
                startIdx = i;
            }
            else if(startIdx != -1 && cnt[s[i] - 'a'] < k)
            {
                impl(s, startIdx, i, k);
                startIdx = -1;
            }

            if(startIdx != -1 && i == endIdx - 1 && cnt[s[i] - 'a'] >= k)
            {
                impl(s, startIdx, i + 1, k);
            }
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.longestSubstring("bbaaacbd", 3)<<std::endl;
}
