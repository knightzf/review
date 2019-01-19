#include "header.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        auto iter = lower_bound(A.begin(), A.end(), 0);
        int i = 0, j = 0;
        if(iter != A.end())
        {
            i = distance(A.begin(), iter);
            j = i - 1;
        }
        else
        {
            i = n;
            j = n - 1;
        }
        cout<<i<<" "<<j<<endl;

        vector<int> res;
        while(i < n || j >= 0)
        {
            if(i < n && j >= 0)
            {
                if(A[i] >= -A[j])
                {
                    res.push_back(A[j] * A[j]);
                    --j;
                }
                else
                {
                    res.push_back(A[i] * A[i]);
                    ++i;
                }
            }
            else if(i < n)
            {
                res.push_back(A[i] * A[i]);
                ++i;
            }
            else
            {
                res.push_back(A[j] * A[j]);
                --j;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{-4,-1,0,3,10};
    s.sortedSquares(a);
}
