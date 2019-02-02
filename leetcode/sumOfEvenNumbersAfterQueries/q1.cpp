#include "header.h"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for_each(A.begin(), A.end(), [&](int i){ if(i % 2 == 0) sum += i;});
        int n = queries.size();
        vector<int> res(n);        
        for(int i = 0; i < n; ++i)
        {
            int val = queries[i][0], idx = queries[i][1];
            int prev = A[idx];
            A[idx] += val;
            if(A[idx] % 2 == 0)
            {
                if(prev % 2 == 0) sum += val;
                else sum += A[idx];
            }
            else
            {
                if(prev % 2 == 0) sum -= prev;
            }
            
            res[i] = sum;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
