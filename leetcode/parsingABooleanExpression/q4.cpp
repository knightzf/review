#include "header.h"

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> oper;
        stack<bool> res;
        stack<bool> compute;
        auto f = [&](bool val) {
            if(compute.empty() || !compute.top()) {
                res.push(val);
            } else {
                switch(oper.top()) {
                    case '!': res.push(!val); break;
                    case '&': res.top() &= val; break;
                    case '|': res.top() |= val; break;
                    default: break;
                }
            }
        };
        for(char c : expression) {
            switch(c) {
                case 't':
                case 'f': {
                    bool val = c == 't' ? true : false;
                    f(val);
                    break;
                }
                case '!':
                case '&':
                case '|':
                    oper.push(c);
                    compute.push(c == '!' ? true : false);
                    break;
                case ',':
                    compute.top() = true;
                    break;
                case ')': {
                    oper.pop();
                    compute.pop();
                    bool val = res.top();
                    res.pop();
                    f(val);
                    break;
                }
                default: break;
            }
        }
        return res.top();
    }
};

int main()
{
    Solution s;
    cout<<s.parseBoolExpr("!(f)")<<endl;
}
