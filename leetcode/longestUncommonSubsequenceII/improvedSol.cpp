#include "header.h"

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const auto& a, const auto& b){
                if(a.size() < b.size()) return true;
                if(a.size() == b.size()) return a < b;
                return false;
             });
        unordered_set<string> m;
        for(int i = strs.size() - 1; i >= 0;)
        {
            int j = i;
            while(j >= 0 && strs[j] == strs[i]) --j;
            if(j == i - 1)
            {
                if(nomatch(m, strs[i])) return strs[i].size();
            }
            m.insert(strs[i]);
            i = j;
        }
        return -1;
    }

    bool nomatch(unordered_set<string>& m, const string& s)
    {
        for(const auto& t : m)
        {
            int m = s.size(), n = t.size();
            int i = 0, j = 0;
            for(; i < m; ++i)
            {
                while(j < n && t[j] != s[i]) ++j;
                if(j == n) break;
                ++j;
            }

            if(i == m && (j != n || (j == n && s.back() == t.back()))) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    //vector<string> a{"aaa", "aaa", "aa"};
    //vector<string> a{"aabbcc", "aabbcc","c"};
    //vector<string> a{"aabbcc", "aabbcc","b"};
    //vector<string> a{"abcabc","abcabc","abcabc","abc","abc","cca"};
    vector<string> a{"aabbcc", "aabbcc","bc","bcc"};
    cout<<s.findLUSlength(a)<<endl;
}
