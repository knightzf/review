#include "header.h"

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        int res = 0;
        unordered_set<int> skip;
        for(int j = 0; j < m; ++j)
        {
            unordered_set<int> temp;
            bool hasDelete = false;
            for(int i = 0; i < n - 1; ++i)
            {
                if(skip.count(i)) continue;
                if(A[i][j] > A[i + 1][j]) 
                {
                    ++res;
                    hasDelete = true;
                    break;
                }
                else if(A[i][j] < A[i + 1][j])
                {
                    temp.insert(i);
                }
            }            

            if(!hasDelete)
            {
                for(int i : temp) skip.insert(i);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}

