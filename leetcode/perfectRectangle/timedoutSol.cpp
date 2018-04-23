#include "header.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //vector<vector<int>> m(1000, vector<int>(1000, 0));
        unordered_map<int, unordered_set<int>> m;
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
                for(int j = v[1]; j < v[3]; ++j)
                {
                    if(m.find(i) == m.end() || m[i].find(j) == m[i].end())
                    {
                        m[i].insert(j);
                        ++cnt;
                    }
                    else if(m.find(i) != m.end() && m[i].find(j) != m[i].end())
                    {
                        return false;
                    }
                }
            }
        }

        return cnt == (topX - bottomX) * (topY - bottomY);
    }
};

int main()
{
    Solution s;
}
