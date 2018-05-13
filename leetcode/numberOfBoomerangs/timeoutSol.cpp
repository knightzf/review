#include "header.h"

class Solution {
public:
    using Test = unordered_map<int, unordered_set<int>>;

    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n < 3) return 0;
        vector<Test> v(n);
        for(int i = 0; i < n - 1; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int dis = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                (points[i].second - points[j].second) * (points[i].second - points[j].second);
                v[i][dis].insert(j);
                v[j][dis].insert(i);
            }
        }

        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(const auto& p : v[i])
            {
                res += p.second.size() * (p.second.size() - 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
