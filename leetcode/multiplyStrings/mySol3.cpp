#include "header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int t = res[i + j] + (num1[i] -'0') * (num2[j] -'0');
                res[i + j] = t % 10;
                res[i + j + 1] += t / 10;
            }
        }
        
        string s;
        for(int i = 0; i < m + n; ++i) s += to_string(res[i]);

        while(s.size() > 1 && s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution s;
}