#include "header.h"

class Solution {
public:
    string decodeString(string s) {
        stack<string> ss;
        stack<int> cs;
        string t; int cnt = 0;
        for(int i = 0, n = s.size(); i < n;) {
            //cout<<i<<endl;
            if(isdigit(s[i])) {
                int j = i;
                while(j < n && isdigit(s[j]))
                    cnt = cnt * 10 + (s[j++] - '0');
                i = j;
            } else if(isalpha(s[i])) {
                int j = i;
                while(j < n && isalpha(s[j]))
                    t += s[j++];
                i = j;
            } else if(s[i] == '[') {
                ss.push(t);
                cs.push(cnt ? cnt : 1);
                t.clear(); cnt = 0;
                ++i;
            } else {
                string x;
                for(int i = 0; i < cs.top(); ++i) x += t;
                cs.pop();
                t = ss.top();
                ss.pop();
                t += x;
                ++i;
            }
        }
        return t;
    }
};

int main()
{
    Solution s;
}