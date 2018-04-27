#include "header.h"

class Solution {
private:
    int m;
    int n;
    int res;

public:
    using Type = pair<int, pair<int, int>>;

    struct Comp{
        bool operator()(const Type& a, const Type& b)
        {
            return a.first > b.first;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        m = heightMap.size(); n = heightMap[0].size(); res = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Type, vector<Type>, Comp> q;
        for(int i = 0; i < n; ++i)
        {
            visited[0][i] = true;
            visited[m - 1][i] = true;
            q.push(make_pair(heightMap[0][i], make_pair(0, i)));
            q.push(make_pair(heightMap[m - 1][i], make_pair(m - 1, i)));
        }
        for(int i = 0; i < m; ++i)
        {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            q.push(make_pair(heightMap[i][0], make_pair(i, 0)));
            q.push(make_pair(heightMap[i][n - 1], make_pair(i, n - 1)));
        }

        int maxHeight = INT_MIN;
        while(!q.empty())
        {
            auto t = q.top();
            q.pop();
            maxHeight = max(maxHeight, t.first);

            visited[t.second.first][t.second.second] = true;
            static vector<int> shift{-1, 0, 1, 0, -1};
            for(int i = 0; i < 4; ++i)
            {
                int j = t.second.first + shift[i];
                int k = t.second.second + shift[i + 1];
                if(j >= 0 && k >= 0 && j < m && k < n && !visited[j][k])
                {
                    if(heightMap[j][k] < maxHeight)
                    {
                        res += maxHeight - heightMap[j][k];
                        heightMap[j][k] = maxHeight;
                    }
                    visited[j][k] = true;
                    q.push(make_pair(heightMap[j][k], make_pair(j, k)));
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
      {1,4,3,1,3,2},
      {3,2,1,3,2,4},
      {2,3,3,2,3,1}
    };
    std::cout<<s.trapRainWater(a)<<std::endl;
}
