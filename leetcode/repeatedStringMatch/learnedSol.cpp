#include "header.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();

        vector<int> prefix(n);
        prefix[0] = 0;
        int len = 0;
        for(int i = 1; i < n; ++i)
        {
            while(len != 0 && B[i] != B[len])
            {
                len = prefix[len - 1];
            }

            prefix[i] = B[i] == B[len] ? (++len) : 0;
        }

        for(int i : prefix)
            cout<<i<<" ";
        cout<<endl;

        int i = 0, j = 0;
        while(i - j < m)
        {
            while(A[i % m] == B[j]) {
                ++i; ++j;
            }

            if(j == n) {
                return i % m == 0 ? (i / m) : (i / m + 1);
            }
            else {
                if(j != 0) {
                    j = prefix[j - 1];
                }
                else {
                    ++i;
                }
            }
        }
        
        return -1;
    }
};

int main() {
    Solution s;
    cout<<s.repeatedStringMatch("aabaa", "aaab")<<endl;
    //s.repeatedStringMatch("aabaaabaaac", "aabaaac");
    //s.repeatedStringMatch("abcabcabcabc", "abac");
    //s.repeatedStringMatch("abaabaa", "abaababaab");
    //s.repeatedStringMatch("abcd", "abcdb");
    //s.repeatedStringMatch("aaaaaaaaaaaaaaaaaaaaaab", "abcdb");
}
