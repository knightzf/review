#include "header.h"

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long i = 0, oper = 0, res = 0, temp = 0;
        stack<tuple<long, long, long>> stk;
        auto calc = [&](long num) {
            switch(oper) {
                case 1: res -= num; temp = -num; break;
                case 2: {
                    res -= temp;
                    res += temp * num;
                    temp = temp * num;
                    break;
                }
                case 3: {
                    res -= temp;
                    res += temp / num;
                    temp = temp / num;
                    break;
                }
                default: res += num; temp = num; break;
            }
        };
        while(i < n) {
            char c = s[i];
            if(isdigit(c)) {
                int j = i;
                while(isdigit(s[j]) && j < n) ++j;
                long num = stol(s.substr(i, j - i));
                i = j;
                calc(num);
            } else {
                switch(c) {
                    case '+': oper = 0; break;
                    case '-': oper = 1; break;
                    case '*': oper = 2; break;
                    case '/': oper = 3; break;
                    case '(': {
                        stk.push({res, temp, oper});
                        res = 0, temp = 0, oper = 0;
                        break;
                    }
                    case ')': {
                        long num = res;
                        res = get<0>(stk.top()), temp = get<1>(stk.top()), oper = get<2>(stk.top());
                        stk.pop();
                        calc(num);
                        break;
                    }
                    default: break;
                }
                ++i;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.calculate("(1 - (3*14/7+2))")<<endl;
}