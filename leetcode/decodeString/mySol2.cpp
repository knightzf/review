#include "header.h"

class Solution {
public:
    string decodeString(string s) {
        deque<string> strStack;
        deque<int> cntStack;
        for(int i = 0, n = s.size(); i < n; ++i) {
            char c = s[i];
            bool newsection = (i == 0 || (isalpha(c) && !isalpha(s[i - 1]))
                               || (isdigit(c) && !isdigit(s[i - 1])));
            if(c == ']') {
                string tt;
                while(!strStack.empty() && !strStack.back().empty()) {
                    string t;
                    for(int i = 0; i < cntStack.back(); ++i) t += strStack.back();
                    tt = t + tt;
                    strStack.pop_back();
                    cntStack.pop_back();
                }
                if(!strStack.empty() && strStack.back().empty()) strStack.back() += tt;
                else {
                    strStack.push_back(tt);
                    cntStack.push_back(1);
                }
            }
            else if(isdigit(c)) {
                if(newsection) {
                    cntStack.push_back(c - '0');
                    strStack.push_back("");
                } else {
                    cntStack.back() = cntStack.back() * 10 + (c - '0');
                }
            } else if(isalpha(c)) {
                if(newsection) {
                    cntStack.push_back(1);
                    strStack.push_back(string(1, c));
                } else {
                    strStack.back() += c;
                }
            }
        }
        string res;
        while(!strStack.empty()) {
            for(int i = 0; i < cntStack.front(); ++i) {
                res += strStack.front();
            }
            cntStack.pop_front();
            strStack.pop_front();
        }
        return res;
    }
};


int main()
{
    Solution s;
    cout<<s.decodeString("3[a]2[bc]")<<endl;
}