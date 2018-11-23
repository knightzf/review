#include "header.h"

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.size();
        vector<int> res(n + 1);
        int left = 0, right = n;
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == 'I')
                res[i] = left++;
            else
                res[i] = right--;
        }

        res[n] = left;
        return res;
    }
};

int main()
{
    Solution s;
}

