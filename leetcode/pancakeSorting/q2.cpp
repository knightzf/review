#include "header.h"

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        unordered_map<int, int> m;
        int n = A.size();
        for(int i = 0; i < n; ++i)
        {
            m[A[i]] = i;
        }

        vector<int> res;
        for(int k = n; k >= 1; --k)
        {
            if(m[k] != k - 1)
            {   
                if(m[k] != 0)
                {
                    res.push_back(m[k] + 1);
                    flip(A, m, m[k]); 
                }                               
                res.push_back(k);
                flip(A, m, k - 1);
            }
        }
        return res;
    }

    void flip(vector<int>& A, unordered_map<int, int>& m, int k)
    {
        for(int i = 0; i <= k / 2; ++i)
        {
            if(i != k - i)
            {
                int a = A[i];
                int b = A[k - i];
                m[a] = k - i;
                m[b] = i;
                swap(A[i], A[k - i]);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> a{3,2,4,1};
    s.pancakeSort(a);
}
