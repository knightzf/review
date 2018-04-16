#include "header.h"

class Solution {
private:
    int n;
    int res;
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        n = A.size();
        res = INT_MAX;
        impl(A, B, 0, 0);
        return res;
    }

    void impl(vector<int>& A, vector<int>& B, int i, int cnt)
    {
        if(i == n)
        {
            res = min(res, cnt);
            return;
        }

        if(i == 0 ||(i > 0 && A[i] > A[i - 1] && B[i] > B[i - 1]))
            impl(A, B, i + 1, cnt);

        std::swap(A[i], B[i]);
        if(i == 0 ||(i > 0 && A[i] > A[i - 1] && B[i] > B[i - 1]))
            impl(A, B, i + 1, cnt + 1);
        //std::swap(A[i], B[i]);
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 3, 5, 4};
    //vector<int> b{1, 2, 3, 7};
    vector<int> a{3,3,8,9,10};
    vector<int> b{1,7,4,6,8};
    std::cout<<s.minSwap(a, b)<<std::endl;
}
