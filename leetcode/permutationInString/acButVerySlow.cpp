#include "header.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s;
        for(char c : s1)
            ++s[c];

        int m = s1.size();
        for(int i = 0, n = s2.size(); i <= n - m;)
        {
            if(s.count(s2[i]))
            {
                auto t = s;
                bool found = true;
                for(int j = i; j < i + m; ++j)
                {
                    if(t.count(s2[j]) == 0)
                    {
                        i = j + 1;
                        found = false;
                        break;
                    }

                    --t[s2[j]];
                    if(t[s2[j]] < 0)
                    {
                        ++i;
                        found = false;
                        break;
                    }
                }
                if(found) return true;
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
