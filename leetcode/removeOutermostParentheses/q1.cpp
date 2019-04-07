#include "header.h"

class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.size();
        int startIdx = 0;
        int count = 0;
        string res;
        for(int i = 0; i < n; ++i)
        {
            if(S[i] == '(') ++count;
            else --count;
            if(count == 0)
            {
                res += S.substr(startIdx + 1, i - startIdx - 1);
                startIdx = i + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}
