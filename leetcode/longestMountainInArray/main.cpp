#include "header.h"

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int res = 0;
        int n = A.size();
        for(int i = 0; i < n - 1;)
        {
            if(A[i] < A[i + 1])
            {
                int j = i + 1 ;
                while(j < n && A[j] > A[j - 1]) ++j;

                if(j < n && A[j] < A[j - 1])
                {
                    while(j < n && A[j] < A[j - 1]) ++j;
                    res = max(res, j - i);
                }
                i = j - 1;
            }
            else
            {
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{2,1,4,7,3,2,5};
    //vector<int> a{875,884,239,731,723,685};
    cout<<s.longestMountain(a)<<endl;
}
