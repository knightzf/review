#include "header.h"

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;
        int res = 1;
        map<int, int> m{{A[n - 1], n - 1}};
        map<int, int> mm{{-A[n - 1], n - 1}};
        for(int i = n - 2; i >= 0; --i)
        {
            auto iter = m.lower_bound(A[i]);
            if(iter != m.end())
            {
                if(dp[iter->second][1])
                {
                    ++res;
                    dp[i][0] = 1;
                }
            }
            
            iter = mm.lower_bound(-A[i]);
            if(iter != mm.end())
            {
                if(dp[iter->second][0])
                {
                    dp[i][1] = 1;
                }
            }

            m[A[i]] = i;
            mm[-A[i]] = i;
        }
        /*for(int i = 0; i < n; ++i)
        {
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }*/
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{5, 1, 3, 4, 2};
    s.oddEvenJumps(a);
}
