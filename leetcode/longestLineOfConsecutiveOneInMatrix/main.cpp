#include "header.h"

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty()) return 0;
        int m = M.size(), n = M[0].size();
        vector<vector<vector<int>>> v(m, vector<vector<int>>(n, vector<int>(4, 0)));
        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(M[i][j] == 1)
                {
                    v[i][j] = {1, 1, 1, 1};
                    if(i > 0 && M[i - 1][j] == 1)
                    {
                        v[i][j][0] += v[i - 1][j][0];
                    }
                    if(j > 0 && M[i][j - 1] == 1)
                    {
                        v[i][j][1] += v[i][j - 1][1];
                    }
                    if(i > 0 && j > 0 && M[i - 1][j - 1] == 1)
                    {
                        v[i][j][2] += v[i - 1][j - 1][2];
                    }
                    if(i > 0 && j < n - 1 && M[i - 1][j + 1] == 1)
                    {
                        v[i][j][3] += v[i - 1][j + 1][3];
                    }
                    res = max(res, v[i][j][0]);
                    res = max(res, v[i][j][1]);
                    res = max(res, v[i][j][2]);
                    res = max(res, v[i][j][3]);
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
