#include "header.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(max(m, n) + 1, 0);
        for(int i = 0, x = max(m, n); i < x; ++i) {
            if(i < m) res[i] += num1[i] - '0';
            if(i < n) res[i] += num2[i] - '0';
            res[i + 1] += res[i] / 10;
        }
        string s;
        int i = max(m, n);
        while(i != 0 && res[i] == 0) --i;
        for(; i >= 0; --i) s += res[i] + '0';
        return s;
    }
};

int main()
{
    Solution s;
}