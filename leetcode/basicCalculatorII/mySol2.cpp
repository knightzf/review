#include "header.h"

class Solution {
public:
    int calculate(string s) {
        int res = 0, temp = 0;
        char oper = '+';
        for(int i = 0, n = s.size(); i < n; ++i) {
            if(isdigit(s[i])) {
                int j = i;
                while(j < n && isdigit(s[j])) ++j;
                int x = stoi(s.substr(i, j - i));
                i = j - 1;
                switch (oper) {
                case '+': res += x; temp = x; break;
                case '-': res -= x; temp = -x; break;
                case '*': res -= temp; temp *= x; res += temp; break;
                case '/': res -= temp; temp /= x; res += temp; break;
                }
            } else if(s[i] != ' ') {
                oper = s[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}