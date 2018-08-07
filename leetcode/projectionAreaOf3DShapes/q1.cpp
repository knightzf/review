#include "header.h"

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int res = 0;
        unordered_map<int, int> xz;
        unordered_map<int, int> yz;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < grid[i].size(); ++j)
            {
                xz[i] = max(xz[i], grid[i][j]);
                yz[j] = max(yz[j], grid[i][j]);
                if(grid[i][j] > 0)
                    ++res;
            }
        }
        for(auto& p : xz)
            res += p.second;
        for(auto& p : yz)
            res += p.second;
        return res;
    }
};

int main()
{
    Solution s;
}
