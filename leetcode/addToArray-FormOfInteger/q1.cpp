#include "header.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B;
        while(K)
        {
            B.push_back(K % 10);
            K /= 10;
        }

        reverse(A.begin(), A.end());

        if(A.size() < B.size()) swap(A, B);

        int b = 0;
        int i = 0;
        for(; i < B.size(); ++i)
        {
            int t = A[i] + B[i] + b;
            if(t > 9)
            {
                b = 1;
                t %= 10;
            }
            else
            {
                b = 0;
            }
            A[i] = t;
        }

        for(; i < A.size() && b != 0; ++i)
        {
            int t = A[i] + b;
            if(t > 9)
            {
                b = 1;
                t %= 10;
            }
            else
            {
                b = 0;
            }
            A[i] = t;          
        }

        if(b != 0) A.push_back(1);
        reverse(A.begin(), A.end());
        return A;        
    }
};

int main()
{
    Solution s;
}
