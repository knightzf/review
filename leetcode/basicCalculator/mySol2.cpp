#include "header.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        for(int n = s.size(), i = n - 1; i >= 0; --i) {
            if(s[i] == ' ') continue;
            if(s[i] == ')' || s[i] == '+' || s[i] == '-') {
                if(s[i] == ')') ss.push(-9997);
                else if(s[i] == '+') ss.push(-9998);
                else ss.push(-9999);
            }
            if(s[i] == '(') {
                int t = 0, sign = 1;
                while(ss.top() != -9997) {
                    if(ss.top() == -9998) sign = 1;
                    else if(ss.top() == -9999) sign = -1;
                    else t += sign * ss.top();
                    ss.pop();
                }
                ss.pop();
                ss.push(t);
            }
            if(isdigit(s[i])) {
                int j = i;
                while(j >= 0 && isdigit(s[j])) --j;
                auto num = stoi(s.substr(j + 1, i - j));
                i = j + 1;
                ss.push(num);
            }
        }
        int res = 0, sign = 1;
        while(!ss.empty()) {
            if(ss.top() == -9998) sign = 1;
            else if(ss.top() == -9999) sign = -1;
            else res += sign * ss.top();
            ss.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
}