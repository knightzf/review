#include "header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
		if(n == 0) return 0;
		vector<int> prefix(n, 0);
		for(int i = 1, len = 0; i < n; ++i)
		{
			while(len != 0 && needle[i] != needle[len]) {
				len = prefix[len - 1];
			}
			if(needle[i] == needle[len]) {
				prefix[i] = ++len;
			}
		}

		int i = 0, j = 0;
		while(i < m)
		{
			while(j != 0 && haystack[i] != needle[j]) 
                j = prefix[j - 1];
			if(haystack[i++] == needle[j]) ++j;
			if(j == n) return i - n;			
		}
		return -1;
    }
};


int main()
{
    Solution s;
	cout<<s.strStr("", "")<<endl;
}