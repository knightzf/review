#include "header.h"

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        int missinglower = 1;
        int missingupper = 1;
        int missingdigit = 1;
        for(int i = 0; i < n; ++i)
        {
            if(missinglower && islower(s[i])) --missinglower;
            if(missingupper && isupper(s[i])) --missingupper;
            if(missingdigit && isdigit(s[i])) --missingdigit;
        }

        int i = 2;
        int change = 0, one = 0, two = 0;
        for(; i < n;)
        {
            if(s[i] == s[i - 1] && s[i - 1] == s[i - 2])
            {
                int j = i + 1;
                while(j < n && s[j] == s[i]) ++j;
                int len = j - i + 2;
                change += len / 3;
                if(len % 3 == 0) ++one;
                else if(len % 3 == 1) ++two;
                i = j;
            }
            else
            {
                ++i;
            }
        }

        int missingtypes = missinglower + missingupper + missingdigit;

        if(n < 6)
        {
            // for n < 6, we have to add, the worse case being n = 5 and all chars are the same
            // we need at least 2 changes, for which case it misses two types of characters
            return max(missingtypes, 6 - n);
        }
        else if(n <= 20)
        {
            // for any subsequence longer than 3, it needs len/3 replacements
            // replacements and adding missing types could be the same thing
            // that's why we do one of them with larger count
            return max(missingtypes, change);
        }
        else
        {
            // for this case, we want to delete at least n - 20 characters
            // how to reuse the deletions for the repeating chars?
            // if len of repeative chars % 3 == 0, we can reduce replacement by 1 by deleting 1 char
            // if % 3 == 1, we can reduce replacement by 1 by deleting 2 chars (e.g. 4 letters, deleting 1 doesn't help, have to delet 2)
            // otherwise, we have to delete 3 to save 1 replacement
            int del = n - 20;
            change -= min(del, one);
            change -= min(max(del - one, 0), two * 2) / 2;
            change -= max(del - one - 2 * two, 0) / 3;
            return del + max(missingtypes, change);
        }
    }
};

int main()
{
    Solution s;
}
