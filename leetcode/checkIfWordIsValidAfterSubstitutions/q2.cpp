#include "header.h"

class Solution {
public:
    bool isValid(string S) {
        if(S == "abc") return true;

        int idx = S.find("abc");
        if(idx == string::npos) return false;

        return isValid(S.substr(0, idx) + S.substr(idx + 3));
    }
};

int main()
{
    Solution s;
}
