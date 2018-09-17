#include "header.h"

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int mod = 1000000007;
        vector<int> right(n, 0);
        vector<int> left(n, 0);
        for(int i = n - 1; i >= 0; --i)
        {
            if(i == n - 1 || A[i] > A[i + 1])
            {
                right[i] = 0;
            }
            else
            {
                int t = 0;
                int j = i + 1;                
                while(A[i] <= A[j] && j < n)
                {
                    t += right[j] + 1;
                    j = j + right[j] + 1;
                }
                right[i] = t;
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || A[i] > A[i - 1])
            {
                left[i] = 0;
            }
            else
            {
                int t = 0;
                int j = i - 1;
                while(A[i] < A[j] && j >= 0)
                {
                    t += left[j] + 1;
                    j = j - left[j] - 1;
                }
                left[i] = t;
            }
        }

        //for(int i = 0; i < n; ++i)
        //    cout<<left[i] << " "<<right[i]<<endl;
        long res = 0;
        for(int i = 0; i < n; ++i)
        {
            cout<<i<<" "<<(1 + left[i] + right[i] + left[i] * right[i])<<endl;
            res += ((1 + left[i] + right[i] + left[i] * right[i]) * A[i]) % mod;
            res %= mod;
        }
        return res;
    }
};

int main()
{
    Solution s;
    //vector<int> a{3, 1, 2, 4};
    vector<int> a{71, 55, 82, 55};
    cout<<s.sumSubarrayMins(a)<<endl;
}

