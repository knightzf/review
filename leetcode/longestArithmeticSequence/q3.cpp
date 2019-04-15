#include "header.h"

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<int, int>> v(n);
        int res = 1;
        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                int diff = A[i] - A[j];
                if(v[j].count(diff))
                {
                    v[i][diff] = max(v[i][diff], v[j][diff] + 1);
                }
                else
                {
                    v[i][diff] = 2;    
                }

                res = max(res, v[i][diff]);           
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}

