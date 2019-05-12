#include "header.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res;
        int distance = numRows * 2 - 2;
        for(int i = 0, n = s.size(); i < numRows; ++i)
        {
            int j = 0;
            while(i + j * distance < n)
            {
                res += s[i + j * distance];
                ++j;
                if(i != 0 && i != numRows - 1 && i + j * distance - 2 * i < n) res += s[i + j * distance - 2 * i];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3)<<endl;
}