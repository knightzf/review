#include "header.h"

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> s1;
        unordered_map<string, int> s2;
        parse(A, s1);
        parse(B, s2);

        vector<string> res;
        for(const auto& p : s1)
        {
            if(p.second == 1 && s2.count(p.first) == 0)
                res.push_back(p.first);
        }
        for(const auto& p : s2)
        {
            if(p.second == 1 && s1.count(p.first) == 0)
                res.push_back(p.first);
        }
        return res;
    }

    void parse(string& A, unordered_map<string, int>& s)
    {
        stringstream ss(A);
        string t;
        while(!ss.eof())
        {
            ss >> t;
            ++s[t];
        }
    }
};

int main()
{
    Solution s;
    const auto& r = s.uncommonFromSentences("this apple is sweet", "this apple is sour");
    for(auto& i : r)
        cout<<i<<endl;
}
