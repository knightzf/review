#include "header.h"

class Solution {
private:
    int m;
    int n;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        static const vector<int> diff{-1, 0, 1, 0, -1};
        set<pair<int, int>> mm;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    for(int k = 0; k < 4; ++k)
                    {
                        int newI = i + diff[k];
                        int newJ = j + diff[k + 1];
                        if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && matrix[newI][newJ] == 1)
                        {
                            res[newI][newJ] = 1;
                            mm.emplace(newI, newJ);
                        }
                    }
                }
            }
        }

        int dis = 2;
        while(!mm.empty())
        {
            set<pair<int, int>> t;
            for(const auto& p : mm)
            {
                for(int k = 0; k < 4; ++k)
                {
                    int newI = p.first + diff[k];
                    int newJ = p.second + diff[k + 1];
                    if(newI >= 0 && newI < m && newJ >= 0 && newJ < n && matrix[newI][newJ] == 1
                       && res[newI][newJ] == 0)
                    {
                        res[newI][newJ] = dis;
                        t.emplace(newI, newJ);
                    }
                }
            }
            mm = t;
            ++dis;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
 {1, 0, 0, 1, 0, 1, 1, 1, 1, 1},
 {1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
 {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
 {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
 {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
 {0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
 {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
 {0, 1, 0, 1, 1, 0, 1, 1, 1, 1},
 {1, 1, 1, 0, 1, 0, 1, 1, 1, 1}};
    s.updateMatrix(a);
}
