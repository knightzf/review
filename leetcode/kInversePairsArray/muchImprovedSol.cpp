#include "header.h"

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> v(n + 1, vector<long>(k + 1, 0));
        for(int i = 1; i < n + 1; ++i)
        {
            for(int j = 0; j < k + 1; ++j)
            {
                if(j == 0) v[i][j] = 1;
                else
                {
                    if(i > 1)
                    {
                        v[i][j] = v[i - 1][j] + 1000000007;
                        if(j - i + 1 > 0)
                            v[i][j] -= v[i - 1][j - i];

                        v[i][j] += v[i][j - 1];
                    }
                }

                v[i][j] %= 1000000007;
            }
        }

        for(int i = 0; i < n + 1; ++i)
        {
            for(int j = 0; j < k + 1; ++j)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

        return v[n][k];
    }
};

int main() {
    Solution s;
    //cout<<s.kInversePairs(3, 0)<<endl;
    //cout<<s.kInversePairs(3, 1)<<endl;
    //cout<<s.kInversePairs(10, 3)<<endl;
    //cout<<s.kInversePairs(10, 4)<<endl;
    cout<<s.kInversePairs(150, 150)<<endl;
}
