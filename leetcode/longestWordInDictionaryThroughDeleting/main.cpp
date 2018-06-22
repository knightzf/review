#include "header.h"

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const auto& a, const auto& b){
                if(a.size() > b.size()) return true;
                if(a.size() == b.size()) return a < b;
                return false;
             });
        int n = s.size();
        for(const auto& t : d)
        {
            if(t.size() <= n)
            {
                int i = 0, j = 0;
                int m = t.size();
                bool found = true;
                for(; i < m; ++i)
                {
                    while(j < n && s[j] != t[i]) ++j;
                    if(j == n)
                    {
                        found = false;
                        break;
                    }
                    ++j;
                }
                if(found) return t;
            }
        }
        return "";
    }
};

int main()
{
    Solution s;
}
