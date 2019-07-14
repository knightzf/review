#include "header.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for(char c : s) ++m[c];
        int cnt = m.size();
        string res;
        char c = 'z' + 1; int i = 0, j = 0;
        while(cnt) {
            if(s[i] < c && m[s[i]] > 0) {
                c = s[i];
                j = i;
            }
            --m[s[i]];
            if(m[s[i]] == 0) {
                res += c;
                --cnt;
                while(i > j) {
                    ++m[s[i--]];
                }
                m[c] = -1;
                c = 'z' + 1;
            }
            ++i;
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.removeDuplicateLetters("cbacdcbc");
}