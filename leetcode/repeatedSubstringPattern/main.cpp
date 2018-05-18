#include "header.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; ++i)
        {
            if(n % (i + 1) == 0)
            {
                const auto& sub = s.substr(0, i + 1);
                int j = i + 1;
                while(s.substr(j, i + 1) == sub)
                {
                    j += i + 1;
                }

                if(j == n) return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
}
