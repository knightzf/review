#include "header.h"

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string t;
        int cnt = 0;
        for(char c : abbr) {
            if(isalpha(c)) {
                if(cnt) {
                    if(t.size() + cnt > word.size()) return false;
                    t += string(cnt, '.');
                    cnt = 0;
                }
                t += c;
            } else {
                if(cnt == 0 && c == '0') return false;
                cnt = cnt * 10 + (c - '0');
            }
        }
        if(cnt) {
            if(t.size() + cnt > word.size()) return false;
            t += string(cnt, '.');
        }
        if(t.size() != word.size()) return false;
        for(int i = 0, n = word.size(); i < n; ++i)
            if(t[i] != '.' && t[i] != word[i]) return false;
        return true;
    }
};

int main()
{
    Solution s;
}