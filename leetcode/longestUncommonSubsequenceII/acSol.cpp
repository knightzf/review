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
                if(m.count(strs[i]) == 0) return strs[i].size();
            }

            string t;
            populate(m, strs[i], 0, t);
            //for(auto i : m)
            //    cout<<i<<endl;

            i = j;
        }
        return -1;
    }

    void populate(unordered_set<string>& m, const string& s, int idx, string& t)
    {
        m.insert(t);
        if(idx == s.size())
        {
            return;
        }

        for(int i = idx; i < s.size(); ++i)
        {
            t += s[i];
            populate(m, s, i + 1, t);
            t.pop_back();
        }
    }
};

int main()
{
    Solution s;
    //vector<string> a{"aaa", "aaa", "aa"};
    //vector<string> a{"aabbcc", "aabbcc","c"};
    vector<string> a{"aabbcc", "aabbcc","b"};
    cout<<s.findLUSlength(a)<<endl;
}
