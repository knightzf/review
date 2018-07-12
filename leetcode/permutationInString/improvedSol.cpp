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
                int beginIdx = i;
                int endIdx = i + m;
                for(int j = beginIdx; j < n && j < endIdx; ++j)
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
                        for(int k = beginIdx; k < j; ++k)
                        {
                            ++t[s2[k]];
                            if(t[s2[j]] == 0)
                            {
                                endIdx += k - beginIdx + 1;
                                beginIdx = k + 1;
                                break;
                            }
                        }
                    }
                }
                if(found)
                {
                    for(auto& p : t)
                    {
                        if(p.second != 0)
                        {
                            found = false;
                            break;
                        }
                    }

                    if(found) return true;
                    i = endIdx;
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
    cout<<s.checkInclusion("hello", "ooolleoooleh")<<endl;
}
