#include "header.h"

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        map<string, int> uniq;
        for(const auto& s : dict)
            ++uniq[s];

        int n = dict.size();
        unordered_map<string, string> m;
        unordered_map<string, unordered_map<int, vector<string>>> abb;
        for(const auto& p : uniq)
        {
            const auto& s = p.first;

            if(p.first.size() <= 3)
            {
                m[s] = s;
                continue;
            }

            if(p.second == 1)
                abb[s.substr(0, 1) + s.back()][s.size() - 2].emplace_back(s);
        }

        for(const auto& p : abb)
        {
            for(const auto& q : p.second)
            {
                int n = q.second.size();
                if(n == 1)
                {
                    m[q.second[0]] = p.first[0] + to_string(q.first) + p.first[1];
                }
                else
                {
                    for(int i = 0; i < n; ++i)
                    {
                        int idx = -1;
                        if(i > 0)
                        {
                            idx = max(idx, impl(q.second, i - 1, i));
                        }
                        if(i < n - 1)
                        {
                            idx = max(idx, impl(q.second, i, i + 1));
                        }

                        string t = q.second[i].substr(0, idx + 1) +
                                        to_string(q.first + 2 - idx - 1 - 1) +
                                        q.second[i].back();
                        if(t.size() < q.first + 2)
                        {
                            m[q.second[i]] = t;
                        }
                        else
                        {
                            m[q.second[i]] = q.second[i];
                        }
                    }
                }
            }
        }

        vector<string> res(n);
        for(int i = 0; i < n; ++i)
        {
            if(uniq.count(dict[i]) == 0)
                res[i] = dict[i];
            else
                res[i] = m[dict[i]];
        }

        return res;
    }

    int impl(const vector<string>& v, int i, int j)
    {
        for(int k = 0; k < v[i].size(); ++k)
        {
            if(v[i][k] != v[j][k]) return k;
        }
    }
};

int main()
{
    Solution s;
    vector<string> a{"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
    const auto& r = s.wordsAbbreviation(a);
    for(auto i : r)
        cout<<i<<" ";
    cout<<endl;
}
