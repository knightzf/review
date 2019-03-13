#include "header.h"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int res = INT_MAX;
        
        function<void(int, int, int)> f = [&](int a, int cntUp, int cntDown)
        {
            for(int i = 1; i < n; ++i)
            {
                if(A[i] != a && B[i] != a) return;
                if(A[i] == a) ++cntUp;
                if(B[i] == a) ++cntDown;
            }

            res = min(res, min(n - cntUp, n - cntDown));
        };
        
        f(A[0], 1, B[0] == A[0] ? 1 : 0);
        f(B[0], B[0] == A[0] ? 1 : 0, 1);
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<int> a{2,1,2,4,2,2};
    vector<int> b{5,2,6,2,3,2};
    cout<<s.minDominoRotations(a, b)<<endl;
}

