#include "header.h"

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int mod = 1e9 + 7;
        unordered_map<int, long> m;
        for(int i : A)
        {
            ++m[i];
        }

        auto combination = [&](int n, int m)
        {
            long res = 1;
            for(int i = n; i > n - m; --i)
            {
                res *= i;
            }

            for(int i = 1; i <= m; ++i)
            {
                res /= i;
            }
            return res % mod;
        };

        long res = 0;
        for(auto& p : m)
        {
            for(auto& q : m)
            {
                int i = p.first, j = q.first;
                int k = target - i - j;
                if(i <= j && j <= k)
                {
                    if(m.count(k))
                    {                    
                        auto ci = m[i];
                        auto cj = m[j];
                        auto ck = m[k];

                        if(i == j && j == k)
                        {
                            if(ci >= 3) res += combination(ci, 3);
                        }
                        else if(i == j)
                        {
                            if(ci >= 2) res += combination(ci, 2) * ck;
                        }
                        else if(j == k)
                        {
                            if(cj >= 2) res += combination(cj, 2) * ci;
                        }
                        else if(i == k)
                        {
                            if(ci >= 2) res += combination(ci, 2) * cj;
                        }
                        else
                        {
                            res += ci * cj * ck;
                        }
                        
                        res %= mod;                 
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,2,2,3,3,4,4,5,5};
    cout<<s.threeSumMulti(a, 8)<<endl;
}