#include "header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        int n = s.size();
        unordered_map<char, int> m;
        for(char c : t)
        {
            ++m[c];
        }

        unordered_map<char, int> tt;
        int cnt = 0, startIdx = 0;
        string res = s;
        bool found = false;
        for(int i = 0; i < n; ++i)
        {
            if(m.find(s[i]) != m.end())
            {
                startIdx = i;
                break;
            }
        }

        for(int i = startIdx; i < n; ++i)
        {
            ++tt[s[i]];
            if(tt[s[i]] <= m[s[i]]) ++cnt;

            if(cnt == t.size())
            {
                for(int j = startIdx; j <= i; ++j)
                {
                    if(m.find(s[j]) != m.end())
                    {
                        if(i - j + 1 <= res.size())
                        {
                            found = true;
                            res = s.substr(j, i - j + 1);
                            if(res.size() == t.size()) return res;
                        }

                        --tt[s[j]];
                        if(tt[s[j]] < m[s[j]])
                        {
                            --cnt;
                            if(cnt < n)
                            {
                                startIdx = j + 1;
                                while(m.find(s[startIdx]) == m.end() && startIdx < n) ++startIdx;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return found ? res : "";
    }
};

int main()
{
    Solution s;
    std::cout<<s.minWindow("ADOBECODEBANC", "ABC")<<std::endl;
}
