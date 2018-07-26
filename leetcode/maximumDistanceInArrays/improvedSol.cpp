#include "header.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int res = 0;
        map<int, vector<int>> m;
        for(int i = 0; i < n; ++i)
        {
            m[arrays[i][0]].emplace_back(i);
            if(arrays[i].size() > 1)
                m[arrays[i].back()].emplace_back(i);
        }

        if(m.size() == 1) return 0;

        if(m.begin()->second.size() * m.rbegin()->second.size() != 1 ||
           m.begin()->second[0] != m.rbegin()->second[0])
            return m.rbegin()->first - m.begin()->first;

        if(m.size() == 2) return 0;

        auto iter = m.begin();
        ++iter;

        auto jter = m.rbegin();
        ++jter;

        return max(abs(m.rbegin()->first - iter->first), abs(m.begin()->first - jter->first));
    }
};

int main() {
    //Solution s;
}
