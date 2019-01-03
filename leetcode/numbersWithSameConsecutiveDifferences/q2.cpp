#include "header.h"

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> res;

        if(N == 1) res = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        else
        {
            function<void(int, int, int)> dfs = [&](int t, int prev, int n)
            {
                if(n == 0)
                {
                    res.push_back(t);
                    return;
                }

                if(prev + K < 10)
                {
                    dfs(t + (prev + K) * pow(10, n - 1), prev + K, n - 1);
                }

                if(K != 0 && prev - K >= 0)
                {
                    dfs(t + (prev - K) * pow(10, n - 1), prev - K, n - 1);
                }
            };

            for(int i = 1; i < 10; ++i)
            {
                dfs(i * pow(10, N - 1), i, N - 1);
            }
        }
        
        return res;
    }
};

int main()
{
    Solution s;
}
