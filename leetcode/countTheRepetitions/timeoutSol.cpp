#include "header.h"

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(s1.size() * n1 < s2.size() * n2) return 0;
        unordered_set<char> t(s1.begin(), s1.end());
        for(char c : s2)
            if(t.find(c) == t.end()) return 0;

        map<int, pair<int, int>> m; //start idx -> {end count, end idx}
        for(int i = 0; i < s1.size(); ++i)
        {
            if(s1[i] == s2[0])
            {
                findS2(s1, s2, i, s1.size(), m);
            }
        }

        //for(const auto& p : m)
        //    std::cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
        int n = 0;
        int startIdx = 0;
        int cntOfS2 = 0;
        while(n < n1)
        {
            auto iter = m.lower_bound(startIdx);
            if(iter == m.end())
            {
                ++n;
                startIdx = 0;
                iter = m.lower_bound(startIdx);
            }

            n += iter->second.first;
            if(n < n1) ++cntOfS2;

            if(iter->second.second + 1 == s1.size())
                ++n;

            startIdx = (iter->second.second + 1) % s1.size();

            //cout << n << " "<<startIdx<<endl;
        }

        //cout << cntOfS2 <<endl;

        return cntOfS2 / n2;
    }

    void findS2(const string& s1, const string& s2, int idx, int n, map<int, pair<int, int>>& m)
    {
        int t = idx;
        for(int i = 0; i < s2.size(); ++i)
        {
            while(s1[idx%n] != s2[i])
                ++idx;
            ++idx;
        }

        m[t] = make_pair((idx - 1) / n, (idx - 1) % n);
    }
};

int main()
{
    Solution s;
    cout<<s.getMaxRepetitions("acb", 4, "ab", 2)<<endl;
    //cout<<s.getMaxRepetitions("aaa", 3, "aa", 1)<<endl;
}
