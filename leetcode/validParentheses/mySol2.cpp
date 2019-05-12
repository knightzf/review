#include "header.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '[':
                case '{':
                    q.push(c);
                    break;
                case ')':
                    if(q.empty() || q.top() != '(') return false;
                    q.pop();
                    break;
                case ']':
                    if(q.empty() || q.top() != '[') return false;
                    q.pop();
                    break;
                case '}':
                    if(q.empty() || q.top() != '{') return false;
                    q.pop();
                    break;
                default: return false;
            }
        }
        return q.empty();
    }
};

int main()
{
    Solution s;
}