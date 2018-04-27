#include "header.h"

class Solution {
private:
    int m;
    int n;
    int res;

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) return 0;
        m = heightMap.size(); n = heightMap[0].size(); res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < n; ++i)
        {
            visited[0][i] = true;
            visited[m - 1][i] = true;
        }
        for(int i = 0; i < m; ++i)
        {
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for(int i = 1; i < m - 1; ++i)
        {
            for(int j = 1; j < n - 1; ++j)
            {
                if(!visited[i][j])
                {
                    set<pair<int, int>> s;
                    std::cout<<i<<" "<<j<<std::endl;
                    while(impl(heightMap, visited, s, i, j)){
                        std::cout<<"in while"<<std::endl;
                    }
                    for(const auto& p : s)
                        visited[p.first][p.second] = true;
                }
            }
        }
        return res;
    }

    bool impl(vector<vector<int>>& heightMap, vector<vector<bool>>& visited, set<pair<int, int>>& s, int i, int j)
    {
        std::cout<<"imp "<<i<<" "<<j<<std::endl;
        int t = heightMap[i][j] + 1;
        if(t <= heightMap[i - 1][j] && t <= heightMap[i + 1][j] &&
           t <= heightMap[i][j - 1] && t <= heightMap[i][j + 1])
        {
            ++res;
            heightMap[i][j] = t;
            std::cout<<i<<" "<<j<<" "<<t<<std::endl;
            return true;
        }

        if((t > heightMap[i - 1][j] && visited[i - 1][j]) ||
           (t > heightMap[i + 1][j] && visited[i + 1][j]) ||
           (t > heightMap[i][j - 1] && visited[i][j - 1]) ||
           (t > heightMap[i][j + 1] && visited[i][j + 1]) )
        {
            visited[i][j] = true;
            return false;
        }

        /*if(t > heightMap[i - 1][j])
        {
            s.insert(make_pair(i - 1, j));
            bool r = impl(heightMap, visited, s, i - 1, j);
            if(r) return true;
        }*/
        if(t > heightMap[i + 1][j])
        {
            s.insert(make_pair(i + 1, j));
            bool r = impl(heightMap, visited, s, i + 1, j);
            if(r) return true;
        }
        /*if(t > heightMap[i][j - 1])
        {
            s.insert(make_pair(i, j - 1));
            bool r = impl(heightMap, visited, s, i, j - 1);
            if(r) return true;
        }*/
        if(t > heightMap[i][j + 1])
        {
            s.insert(make_pair(i, j + 1));
            bool r = impl(heightMap, visited, s, i, j + 1);
            if(r) return true;
        }
        return false;
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
