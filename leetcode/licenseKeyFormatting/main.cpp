#include "header.h"

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.size();
        string res;
        int cnt = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if(isalnum(S[i]))
            {
                if(isalpha(S[i]))
                    res += toupper(S[i]);
                else
                    res += S[i];
                ++cnt;
                if(cnt == K)
                {
                    res += '-';
                    cnt = 0;
                }
            }
        }
        if(res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
}
