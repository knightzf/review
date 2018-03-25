#include "header.h"

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<int> top(n);
        vector<int> left(m);

        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] > top[j]) top[j] = grid[i][j];
                if(grid[i][j] > left[i]) left[i] = grid[i][j];
            }
        }

        int res = 0;
        for(int i = 0; i < m ; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res += min(grid[i][j] < top[j] ? top[j] - grid[i][j] : 0,
                           grid[i][j] < left[i]  ? left[i]  - grid[i][j] : 0);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{
        {3, 0, 8, 4},
        {2, 4, 5, 7},
        {9, 2, 6, 3},
        {0, 3, 1, 0}
    };

    std::cout<<s.maxIncreaseKeepingSkyline(a)<<std::endl;
}
