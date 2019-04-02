#include "header.h"

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        int rightZeros = 0, leftOnes = 0;
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == '0') ++rightZeros;
        }

        int res = rightZeros;

        for(int i = 0; i < n; ++i)
        {
            if(S[i] == '1')
            {
                ++leftOnes;
            }
            else
            {
                --rightZeros;
            }
            res = min(res, leftOnes + rightZeros);           
        }
        return res;
    }
};

int main()
{
    Solution s;
}