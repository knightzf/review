#include "header.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        int sign = 1;
        int res = 0;
        for(int i = 0, n = s.size(); i < n; ++i) {
            if(s[i] == ' ') continue;
            if(isdigit(s[i])) {
                int j = i;
                while(j < n && isdigit(s[j])) ++j;
                res += sign * stoi(s.substr(i, j - i));
                i = j - 1;
            }
            if(s[i] == '+') {
                sign = 1;
            }
            if(s[i] == '-') {
                sign = -1;
            }
            if(s[i] == '(') {
                ss.push(res);
                ss.push(sign);
                res = 0, sign = 1;
            }
            if(s[i] == ')') {
                if(!ss.empty()) {
                    sign = ss.top(); ss.pop();
                    res = ss.top() + sign * res;
                    ss.pop();
                }
            }            
        }
        
        return res;
    }
};

int main()
{
    Solution s;
}