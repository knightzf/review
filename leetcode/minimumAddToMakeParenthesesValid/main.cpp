#include "header.h"

class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        int res = 0;
        for(char c : S) {
            if(c == '(') ++cnt;
            else --cnt;
            if(cnt < 0) ++res, ++cnt;
        }
        return res + cnt;
    }
};

int main()
{
    Solution s;
}