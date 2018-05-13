#include "header.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i)
        {
            std::reverse(A[i].begin(), A[i].end());
            for_each(A[i].begin(), A[i].end(), [](int& i){
                        i = (i == 0 ? 1 : 0);
                     });
        }
        return A;
    }
};

int main()
{
    Solution s;
}
