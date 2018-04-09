#include "header.h"

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<pair<int, int>> m;
        int totalLen = 0;
        for(const auto& v : wall)
        {
            int i = 0;
            for(int b : v)
            {
                m.emplace_back(i, 1);
                i += b;
                m.emplace_back(i, -1);
            }
            if(totalLen == 0) totalLen = m.back().first;
        }

        std::sort(m.begin(), m.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                  if(a.first < b.first) return true;
                  else if(a.first == b.first) return a.second < b.second;
                  return false;
                  });
        int res = INT_MAX;
        int cnt = 0;
        for(const auto& p : m)
        {
            if(p.second > 0) ++cnt;
            else
            {
                --cnt;
                if(p.first != totalLen)
                    res = min(res, cnt);
            }
        }

        return res == INT_MAX ? wall.size() : res;
    }
};

int main()
{
    Solution s;
}
