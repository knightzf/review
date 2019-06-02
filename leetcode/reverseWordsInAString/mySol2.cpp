#include "header.h"

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res;
        for(int i = n - 1, endIdx = n - 1; i >= -1; --i) {
            if(s[endIdx] == ' ') {
                endIdx = i;
                continue;
            }
            if(i == -1 || s[i] == ' ') {
                if(!res.empty()) res += ' ';
                res += s.substr(i + 1, endIdx - i);
                endIdx = i;
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;    
}