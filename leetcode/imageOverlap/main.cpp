#include "header.h"

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        if(n == 0) return 0;
        int N = 2*(n - 1) + 1;
        vector<vector<int>> t(N, vector<int>(N, 0));
        for(int i = n - 1; i < N; ++i)
        {
            for(int j = n - 1; j < N; ++j)
            {
                t[i][j] = B[i - n + 1][j - n + 1];
            }
        }

        /*for(const auto& i : t)
        {
            for(int j : i)
                std::cout<<j<<" ";
            std::cout<<std::endl;
        }*/

        int maxCnt = 0;
        for(int i = 0; i < N; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                int cnt = 0;
                for(int k = 0; k < n && k + i < N; ++k)
                {
                    for(int m = 0; m < n && m + j < N; ++m)
                    {
                        if(A[k][m] == 1 && t[k + i][m + j] == 1)
                            ++cnt;
                    }
                }
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
