#include "header.h"

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int m = A.size(), n = B.size();
        vector<int> prefix(n, 0);
        for(int i = 1, len = 0; i < n;) {
            if(B[i] == B[len]) prefix[i++] = ++len;
            else if(len) len = prefix[len - 1];
            else prefix[i++] = 0;
        }
        for(int i = 0, j = 0; i < m; i += max(1, j - prefix[j - 1]), j = prefix[j - 1]) {
            while(j < n && A[(i + j) % m] == B[j]) ++j;
            if(j == n) return ceil(float(i + j) / m);
        }
        return -1;
    }
};

int main()
{
    //Solution s;
}