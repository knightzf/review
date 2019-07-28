#include "header.h"

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> chge(n, n); chge[0] = 1;
        vector<int> stay(n, n); stay[0] = 0;
        for(int i = 1; i < n; ++i) {
            if(A[i] > A[i - 1] && B[i] > B[i - 1]) {
                stay[i] = min(stay[i], stay[i - 1]);
                chge[i] = min(chge[i], chge[i - 1] + 1);
            }
            if(A[i] > B[i - 1] && B[i] > A[i - 1]) {
                stay[i] = min(stay[i], chge[i - 1]);
                chge[i] = min(chge[i], stay[i - 1] + 1);
            }
        }
        return min(stay[n - 1], chge[n - 1]);
    }
};


int main()
{
    Solution s;
    vector<int> a{0,7,8,10,10,11,12,13,19,18}, b{4,4,5,7,11,14,15,16,17,20};
    cout<<s.minSwap(a, b)<<endl;
}