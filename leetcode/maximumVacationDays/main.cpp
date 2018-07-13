#include "header.h"

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = flights.size();
        int K = days[0].size();

        vector<vector<int>> maxdays(N, vector<int>(K, 0));
        for(int i = 0; i < N; ++i)
        {
            if(i == 0 || flights[0][i])
                maxdays[i][0] = days[i][0];
            else
                maxdays[i][0] = -1;
        }

        for(int j = 1; j < K; ++j)
        {
            for(int i = 0; i < N; ++i)
            {
                int t = -1;
                for(int k = 0; k < N; ++k)
                {
                    if((k == i || flights[k][i]) && maxdays[k][j - 1] >= 0)
                    {
                        t = max(t, maxdays[k][j - 1] + days[i][j]);
                    }
                }
                maxdays[i][j] = t;
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i)
            res = max(res, maxdays[i][K - 1]);
        return res;
    }
};

int main()
{
    Solution s;
}
