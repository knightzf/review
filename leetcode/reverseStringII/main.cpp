#include "header.h"

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n; i += k)
        {
            if(i / k % 2 == 0)
            {
                int j = (i + k > n) ? n : (i + k);
                reverse(s.begin() + i, s.begin() + j);
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
}
