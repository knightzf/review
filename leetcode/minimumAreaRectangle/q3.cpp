#include "header.h"

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> m;
        for(auto& p : points)
        {
            m[p[0]].insert(p[1]);
        }
        int res = INT_MAX;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            int x = iter->first;
            auto jter = iter; ++jter;
            for(; jter != m.end(); ++jter)
            {
                std::vector<int> v;  
                std::set_intersection(iter->second.begin(), iter->second.end(), 
                    jter->second.begin(), jter->second.end(), back_inserter(v));
                if(v.size() > 1)
                {
                    for(int i = 0; i < v.size() - 1; ++i)
                    {
                        res = min(res, (v[i + 1] - v[i]) * (jter->first - iter->first));
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution s;
}

