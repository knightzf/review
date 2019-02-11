#include "header.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        unordered_map<int, int> s;
        vector<int> dp(n, 0);
        for(int i = 0, j = 0; i < n; ++i)
        {
            ++s[A[i]];

            if(s.size() == K)
            {
                int k = i;
                while(k < n && s.count(A[k]))
                {
                    ++k;
                    ++dp[j];
                }

                while(j < k)
                {
                    --s[A[j]];
                    if(s[A[j]] == 0) 
                    {
                        s.erase(A[j]);
                        ++j;
                        break;
                    }
                    ++j;
                    dp[j] = dp[j - 1];                  
                }
            }
        }
        for(int i : dp) cout<<i<<endl;
        int res = accumulate(dp.begin(), dp.end(), 0);
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,2,1,2,3};
    //cout<<s.subarraysWithKDistinct(a, 2)<<endl;
    //vector<int> a{1,2,1,3,4};
    //cout<<s.subarraysWithKDistinct(a, 3)<<endl;
    vector<int> a{2,2,1,2,2,2,1,1};
    cout<<s.subarraysWithKDistinct(a, 2)<<endl;
}
