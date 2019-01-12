#include "header.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int, vector<int>> m;

        for(int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];
            m[x * x + y * y].push_back(i);
        }

        vector<vector<int>> res;
        for(auto iter = m.begin(); iter != m.end(); ++iter)
        {
            if(res.size() == K) break;
            for(int i : iter->second)
            {
                res.push_back(points[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
