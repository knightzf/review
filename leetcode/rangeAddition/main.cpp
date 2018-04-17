#include "header.h"

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int, int> m;
        for(const auto& v : updates)
        {
            m[v[0]] += v[2];
            m[v[1] + 1] -= v[2];
        }

        vector<int> res(length, 0);
        int t = 0;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if(iter->first < length)
            {
                t += iter->second;
                auto jter = iter; ++jter;
                if(jter == m.end())
                {
                    res[iter->first] = t;
                }
                else
                {
                    for(int i = iter->first; i < jter->first; ++i)
                    {
                        res[i] = t;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {2,4,6},
        {5,6,8},
        {1,9,-4}
    };
    s.getModifiedArray(10, a);
}
