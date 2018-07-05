#include "header.h"

class Solution {
public:
    int checkRecord(int n) {
        vector<long> m(n + 1);
        m[0] = 1;
        vector<vector<long>> v(n, vector<long>(2, 0));
        int mod = 1000000007;
        for(int i = 0; i < n; ++i)
        {
            v[i][0] = i > 0 ? (v[i - 1][0] + v[i - 1][1]) % mod : 1;
            if(i == 0)
                v[i][1] = 1;
            else if(i == 1)
                v[i][1] = (v[i - 1][0] + v[i - 1][1]) % mod;
            else
                v[i][1] = (v[i - 2][0] + v[i - 1][0]) % mod;

            m[i + 1] = v[i][0] + v[i][1];
        }

        /*for(const auto& i : v)
        {
            for(const auto& j : i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }

        for(int i = 0; i < n + 1; ++i)
            cout<<m[i]<<" ";
        cout<<endl;*/

        long res = 0;
        for(int i = 0; i <= n; ++i)
        {
            //cout<<i<<" "<<n - i<<endl;
            res += m[i == 0 ? i : (i - 1)] * m[n - i];
            res %= mod;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.checkRecord(5)<<endl;
}
