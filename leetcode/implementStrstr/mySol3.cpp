#include "header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0) return 0;
        vector<int> prefix(n, 0);
        for(int i = 1, len = 0; i < n;) {
            if(needle[i] == needle[len]) prefix[i++] = ++len;
            else if(len) len = prefix[len - 1];
            else prefix[i++] = 0;
        }
        for(int i = 0, j = 0; i < m && j < n;) {
            if(haystack[i] == needle[j]) ++i, ++j;
            else if(j == 0) ++i;
            else j = prefix[j - 1];
            if(j == n) return i - n;
        }
        return false;
    }
};

int main()
{
    Solution s;
}