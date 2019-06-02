#include "header.h"

class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        for(int i = 0, j = 0, n = str.size(); i < n; ++j) {
            if(j + 1 == n || str[j + 1] == ' ') {
                reverse(str.begin() + i, str.begin() + j + 1);
                ++j;
                i = j + 1;
            }
        }
    }
};

int main()
{
    Solution s;
}