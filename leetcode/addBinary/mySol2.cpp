#include "header.h"

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int m = a.size(), n = b.size();
        string res(max(m, n) + 1, '0');
        res.replace(res.begin(), res.begin() + m, a);
        for(int i = 0; i < n; ++i) {
            int t = res[i] - '0' + b[i] - '0';
            if(t >= 2) {
                res[i] = t - 2 + '0';
                res[i + 1] += 1;
            }
            else {
                res[i] = '0' + t;
            }
        }
        for(int i = n; i < res.size() - 1; ++i) {
            if(res[i] - '0' >= 2) {
                res[i] = '0';
                res[i + 1] += 1;
            } else break;
        }
        reverse(res.begin(), res.end());
        if(res.size() > 1 && res[0] == '0') return res.substr(1);
        return res; 
    }
};


int main()
{
    Solution s;
    s.addBinary("1010", "1011");
}