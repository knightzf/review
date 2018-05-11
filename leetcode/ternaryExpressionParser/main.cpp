#include "header.h"

class Solution {
public:
    string parseTernary(string expression) {
        return impl(expression, 0, expression.size());
    }

    string impl(const string& expression, int startIdx, int endIdx)
    {
        int cnt = 0;
        int conditionEndIdx;
        for(int i = startIdx; i < endIdx; ++i)
        {
            char c = expression[i];
            if(c == '?')
            {
                if(cnt == 0)
                    conditionEndIdx = i;
                ++cnt;
            }
            else if(c == ':')
            {
                if(cnt == 1)
                {
                    const string& condition = expression.substr(startIdx, conditionEndIdx - startIdx);
                    if(condition == "T") return impl(expression, conditionEndIdx + 1, i);
                    return impl(expression, i + 1, endIdx);
                }
                --cnt;
            }
        }
        return expression.substr(startIdx, endIdx - startIdx);
    }
};

int main()
{
    Solution s;
    s.parseTernary("T?2:3");
}
