#include "header.h"

class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() < 3) return true;
        return impl(s, 0, s.size() - 1);

    }

    bool impl(const string& s, int i, int j, bool secondtry = false)
    {
        while(i < j)
        {
            if(s[i] != s[j])
            {
                if(secondtry) return false;
                return impl(s, i + 1, j, true) || impl(s, i, j - 1, true);
            }
            ++i; --j;
        }
        return true;
    }
};

int main()
{
    Solution s;
}
