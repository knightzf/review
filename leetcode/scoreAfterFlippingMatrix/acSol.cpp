#include "header.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();

        for(int i = 0; i < m; ++i)
        {
            if(A[i][0] == 0)
            {
                flip(A[i]);
            }
        }

        for(int i = 1; i < n; ++i)
        {
            if(cnt(A, i, m) <= m / 2)
            {
                flip(A, i, m);
            }
        }

        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            res += calc(A[i], n);
        }
        return res;
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

    int cnt(vector<vector<int>>& A, int i, int m)
    {
        int res = 0;
        for(int j = 0; j < m; ++j)
        {
            res += A[j][i];
        }
        return res;
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
