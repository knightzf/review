#include "header.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        t = s + '#' + t;
        vector<int> lcp(t.size(), 0);
        for(int i = 1, len = 0, n = t.size(); i < n;) {
            if(t[i] == t[len]) {
                lcp[i++] = ++len;
            } else if(len) {
                len = lcp[len - 1];
            } else {
                ++i;
            }
        }
        int len = lcp.size() == 0 ? 1 : lcp.size();
        string tt = s.substr(len); 
        reverse(tt.begin(), tt.end());
        return tt + s;
    }
};

int main()
{
    //Solution s;
}