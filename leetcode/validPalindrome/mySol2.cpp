#include "header.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j)
        {
            if(!isalnum(s[i])) { ++i; continue; }
            if(!isalnum(s[j])) { --j; continue; }
            if(s[i] == s[j] || toupper(s[i]) == toupper(s[j])) {
                ++i; --j;
                continue;
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    
}