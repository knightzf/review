#include "header.h"

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0;
        unordered_map<int, int> m{{0, 1}};

        int sum = 0;
        for(int i = 0, n = A.size(); i < n; ++i)
        {
            sum += A[i];
            int t = sum % K;
            if(m.count(t))
            {
                res += m[t];
            }

            if(m.count(t - K))
            {
                res += m[t - K];
            }

            if(m.count(t + K))
            {
                res += m[t + K];
            }

            ++m[t];
        }
        return res;
    }
};

int main()
{
    Solution s;
}

