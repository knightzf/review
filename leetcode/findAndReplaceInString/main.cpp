#include "header.h"

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = S.size();
        if(indexes.empty()) return S;

        map<pair<int, int>, string> m;
        for(int i = 0; i < indexes.size(); ++i)
        {
            if(S.substr(indexes[i], sources[i].size()) == sources[i])
            {
                m[make_pair(indexes[i], indexes[i] + sources[i].size() - 1)] = targets[i];
            }
        }

        if(m.empty()) return S;
        string res = S.substr(0, m.begin()->first.first);
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if(iter != m.begin())
            {
                auto jter = iter;
                --jter;
                if(jter->first.second != iter->first.first - 1)
                {
                    res += S.substr(jter->first.second + 1, iter->first.first - jter->first.second - 1);
                }
            }
            res += iter->second;
        }

        if(m.rbegin()->first.second != n - 1)
            res += S.substr(m.rbegin()->first.second + 1);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{0, 2};
    vector<string> b{"ab", "ec"};
    vector<string> c{"eee", "ffff"};
    std::cout<<s.findReplaceString("abcd", a, b, c)<<std::endl;
}
