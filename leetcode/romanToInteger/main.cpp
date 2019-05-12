#include "header.h"

class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> m{
            {'V', 5},
            {'L', 50},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        for(int i = 0, n = s.size(); i < n; ++i)
        {
            if(s[i] == 'I')
            {
                if(i < n - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
                    res -= 1;
                }
                else res += 1;
            }
            else if(s[i] == 'X')
            {
                if(i < n - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
                    res -= 10;
                }
                else res += 10;
            }
            else if(s[i] == 'C')
            {
                if(i < n - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                {
                    res -= 100;
                }
                else res += 100;
            }
            else res += m[s[i]];
        }
        return res;
    }
};

int main()
{
    Solution s;
}