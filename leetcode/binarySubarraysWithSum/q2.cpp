#include "header.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        int res = 0;

        if(S == 0)
        {
            for(int i = 0; i < n;)
            {
                if(A[i] == 0)
                {
                    int j = i;
                    while(j < n && A[j] == 0) ++j;
                    res += (1 + j - i) * (j - i) / 2;
                    i = j;
                }
                else ++i;
            }
            return res;
        }
        
        vector<int> v{0};
        for(int i = 0; i < n; ++i)
        {
            if(A[i] == 1)
            {
                v.push_back(i);
            }
        }
        
        for(int i = 1; i < v.size(); ++i)
        {            
            if(i + S - 1 < v.size())
            {
                int startIdx = v[i];
                int endIdx = v[i + S - 1];
                int leftZero = 0, rightZero = 0;
                while(startIdx - 1 >= 0 && A[startIdx - 1] == 0)
                {
                    ++leftZero;
                    --startIdx;
                }
                while(endIdx + 1 < n && A[endIdx + 1] == 0)
                {
                    ++rightZero;
                    ++endIdx;
                }
                res += (leftZero + 1) * (rightZero + 1);
            }
            else break;
        }
        return res;
    }    
};

int main()
{
    Solution s;
}
