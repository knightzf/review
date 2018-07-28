#include "header.h"

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> v(n + 1, vector<long>(k + 1, -1));
        for(int i = 1; i < n + 1; ++i)
            v[i][0] = 1;

        /*auto res = impl(v, n, k);

        for(int i = 0; i < n + 1; ++i)
        {
            for(int j = 0; j < k + 1; ++j)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }


        return res;*/
        return impl(v, n, k);
    }

    int impl(vector<vector<long>>& v, int n, int k)
    {
        if(v[n][k] == -1)
        {
            if(n * (n - 1) / 2 < k)
            {
                v[n][k] = 0;
            }
            else
            {
                //cout<<"i "<<min(k, n - 1)<<endl;
                v[n][k] = 0;
                for(int i = min(k, n - 1); i >= 0; --i)
                    v[n][k] += impl(v, n - 1, k - i);
                v[n][k] %= 1000000007;
            }
        }

        return v[n][k];
    }
};

int main() {
    Solution s;
    cout<<s.kInversePairs(3, 0)<<endl;
    cout<<s.kInversePairs(3, 1)<<endl;
}
