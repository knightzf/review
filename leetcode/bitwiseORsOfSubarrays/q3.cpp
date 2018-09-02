#include "header.h"

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int n = A.size();
        unordered_set<int> s;
        int t = 0;
        for(int i = 0; i < n; ++i)
        {
            t = t | A[i];
            s.insert(t);
        }

        for(int i = 1; i < n; ++i)
        {
            if((A[i] & A[i - 1]) != A[i - 1])
            {                
                int t = 0;
                for(int j = i; j < n; ++j)
                {
                    t = t | A[j];
                    s.insert(t);
                    if((t & A[i - 1]) == A[i - 1])
                        break;
                }
            }
        }
        return s.size();
    }
};

int main()
{
    Solution s;
    vector<int> a{1, 1, 2};
    cout<<s.subarrayBitwiseORs(a)<<endl;
}

