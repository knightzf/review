#include "header.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        unordered_set<char> s;
        for(char c : s1)
            s.insert(c);

        int m = s1.size();
        for(int i = 0, n = s2.size(); i <= n - m;)
        {
            if(s.count(s2[i]))
            {
                bool precheck = true;
                int j = i;
                for(; j < i + m; ++j)
                {
                    if(s.count(s2[j]) == 0)
                    {
                        precheck = false;
                        break;
                    }
                }

                if(precheck)
                {
                    auto t = s2.substr(i, m);
                    sort(t.begin(), t.end());
                    if(t == s1) return true;
                    ++i;
                }
                else
                {
                    i = j + 1;
                }
            }
            else
            {
                ++i;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
}
