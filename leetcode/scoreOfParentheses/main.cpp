#include "header.h"

class Solution {
public:
    int scoreOfParentheses(string S) {
        int n = S.size();
        return impl(S, 0, n - 1);
    }

    int impl(const string& s, int startIdx, int endIdx)
    {
        if(startIdx + 1 == endIdx) return 1;

        int res = 0;
        int cnt = 0;
        int idx = startIdx;
        bool hasSub = false;
        for(int i = startIdx; i <= endIdx; ++i)
        {
            cnt += (s[i] == '(' ? 1 : -1);
            if(cnt == 0)
            {
                if(i == endIdx && hasSub == false) break;

                hasSub = true;
                res += impl(s, idx, i);
                idx = i + 1;
            }
        }

        if(!hasSub)
        {
            res = 2 * impl(s, startIdx + 1, endIdx - 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
}
