#include "header.h"

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        int mod = 1e9 + 7;
        static vector<long> m(20000, 0);
        if(m[0] == 0)
        {
            m[0] = 1;
            for(int i = 1; i < 20000; ++i)
            {
                m[i] = m[i - 1] * 2 % mod;
            }
        }

        sort(A.begin(), A.end());

        long res = 0;
        for(int i = 0, n = A.size(); i < n - 1; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(A[j] > A[i])
                {
                    res += m[j - i - 1] * (A[j] - A[i]) % mod;
                    res %= mod;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{3,7,2,3};
    vector<int> a{2,1,3};
    cout<<s.sumSubseqWidths(a)<<endl;
}
