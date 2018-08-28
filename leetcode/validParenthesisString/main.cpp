#include "header.h"

class Solution {
public:
    bool checkValidString(string s) {
        if(s.empty()) return true;
        int n = s.size();
        int cnt = 0;
        int starCnt = 0;
        for(int i = 0; i < n; ++i)
        {
            char c = s[i];
            if(c == '(') --cnt;
            else if(c == ')') ++cnt;
            else ++starCnt;
            if(cnt > starCnt) return false;
        }
        cnt = 0;
        starCnt = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            char c = s[i];
            if(c == ')') --cnt;
            else if(c == '(') ++cnt;
            else ++starCnt;
            if(cnt > starCnt) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout<<s.checkValidString("()")<<endl;
    cout<<s.checkValidString("(*)")<<endl;
    cout<<s.checkValidString("(*))")<<endl;
}
