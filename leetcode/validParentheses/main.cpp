#include "header.h"

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ss;
        for(char c : s)
        {
            switch(c)
            {
            case '(':
            case '[':
            case '{':
                ss.push(c);
                break;
            case ')':
            case ']':
            case '}':
                {
                    if(ss.empty() || !isOpposite(ss.top(), c))
                        return false;
                    ss.pop();
                    break;
                }
            default:
                break;
            }
        }

        return ss.empty();
    }
private:
    bool isOpposite(char c, char d)
    {
        switch(c)
        {
        case '(':
            return d == ')';
        case '[':
            return d == ']';
        case '{':
            return d == '}';
        }
        return false;
    }
};

int main()
{
    Solution s;
}
