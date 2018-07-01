#include "header.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        set<vector<vector<int>>> stateMap;
        int res = 0;
        dfs(A, m, n, res, stateMap);
        return res;
    }

    void dfs(vector<vector<int>>& A, int m, int n, int& res, set<vector<vector<int>>>& stateMap)
    {
        if(stateMap.count(A)) return;
        stateMap.insert(A);

        int t = 0;
        for(int i = 0; i < m; ++i)
        {
            t += calc(A[i], n);
        }
        res = max(res, t);

        for(int i = 0; i < m; ++i)
        {
            flip(A[i]);
            dfs(A, m, n, res, stateMap);
            flip(A[i]);
        }

        for(int i = 0; i < n; ++i)
        {
            flip(A, i, m);
            dfs(A, m, n, res, stateMap);
            flip(A, i, m);
        }
    }

    int calc(vector<int>& v, int n)
    {
        int res = 0;
        int t = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            res += t * v[i];
            t *= 2;
        }
        return res;
    }

    void flip(vector<vector<int>>& A, int i, int m)
    {
        for(int j = 0; j < m; ++j)
        {
            if(A[j][i] == 1)
            {
                A[j][i] = 0;
            }
            else
            {
                A[j][i] = 1;
            }
        }
    }

    void flip(vector<int>& v)
    {
        for(int& i : v)
        {
            i = (i == 1 ? 0 : 1);
        }
    }
};

int main()
{
    Solution s;
}
