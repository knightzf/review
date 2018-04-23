#include "header.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        struct cmp
        {
            bool operator() (const pair<int, int>& a, const pair<int, int>& b){return a.first < b.first;}
        };
        unordered_map<int, set<pair<int, int>, cmp>> m;
        int bottomX = INT_MAX, bottomY = INT_MAX, topX = -1, topY = -1;
        int cnt = 0;
        for(const auto& v : rectangles)
        {
            bottomX = min(bottomX, v[1]);
            topX = max(topX, v[1]);
            bottomX = min(bottomX, v[3]);
            topX = max(topX, v[3]);

            bottomY = min(bottomY, v[0]);
            topY = max(topY, v[0]);
            bottomY = min(bottomY, v[2]);
            topY = max(topY, v[2]);

            for(int i = v[0]; i < v[2]; ++i)
            {
                const auto& r = m[i].insert(make_pair(v[1], v[3] - 1));
                if(!r.second) return false;
                auto iter = r.first;
                if(iter != m[i].begin())
                {
                    --iter;
                    if(iter->second >= v[1]) return false;
                    iter = r.first;
                }
                ++iter;
                if(iter != m[i].end() && iter->first <= v[3] - 1) return false;
                cnt += v[3] - v[1];
                //std::cout<<i<<" "<<v[3] - v[1]<<std::endl;
            }
        }

        return cnt == (topX - bottomX) * (topY - bottomY);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
    std::cout<<s.isRectangleCover(a)<<std::endl;
}
