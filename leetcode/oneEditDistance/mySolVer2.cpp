#include "header.h"

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size()) std::swap(s, t);
        if(s.size() - t.size() > 1) return false;

        int m = s.size(), n = t.size();
        if(m == n)
        {
            int cnt = 0;
            for(int i = 0; i < m; ++i)
            {
                if(s[i] != t[i]) ++cnt;
                if(cnt > 1) return false;
            }
            return cnt == 1;
        }
        else
        {
            int i = 0, j = 0;
            int cnt = 0;
            while(i < m && j < n)
            {
                if(s[i] != t[j])
                {
                    ++cnt;
                    ++i;
                    break;
                }
                ++i;
                ++j;
            }
            return cnt == 0 ? true : s.substr(i) == t.substr(j);
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.isOneEditDistance("", "A")<<std::endl;
}
