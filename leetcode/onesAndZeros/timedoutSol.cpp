#include "header.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        return impl(strs, m, n, len - 1);
    }

    int impl(vector<string>& strs, int m, int n, int idx)
    {
        if(idx == -1) return 0;

        int zeroCnt = 0;
        int oneCnt = 0;
        for(char c : strs[idx])
        {
            if(c == '0') ++zeroCnt;
            else ++oneCnt;
        }

        if(zeroCnt <= m && oneCnt <= n)
        {
            return max(1 + impl(strs, m - zeroCnt, n - oneCnt, idx - 1),
                       impl(strs, m, n, idx - 1));
        }
        else
            return impl(strs, m, n, idx - 1);

    }
};

int main()
{
    Solution s;
}
