#include "header.h"

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n < 3) return 0;
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            unordered_map<int, int> m;
            for(int j = 0; j < n; ++j)
            {
                if(i != j)
                {
                    int dis = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
                        (points[i].second - points[j].second) * (points[i].second - points[j].second);
                    ++m[dis];
                }
            }
            for(const auto& p : m)
            {
                res += p.second * (p.second - 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
