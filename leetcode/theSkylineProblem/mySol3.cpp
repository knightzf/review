#include "header.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> edges;
        for(const auto& v : buildings) {
            edges.emplace_back(make_pair(v[0], v[2]));
            edges.emplace_back(make_pair(v[1], -v[2]));
        }
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
            if(a.first < b.first) return true;
            if(a.first > b.first) return false;
            return a.second > b.second;
        });

        map<int, int> m;
        int curr = 0;
        vector<vector<int>> res;
        for(const auto& p : edges) {
            if(p.second > 0) ++m[p.second];
            else {                
                --m[-p.second];
                if(!m[-p.second]) m.erase(-p.second);
            }
            int top = m.empty() ? 0 : m.rbegin()->first;
            if(top != curr) {
                curr = top;
                res.push_back(vector<int>{p.first, curr});
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}