#include "header.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res, right;
        bool neg = (numerator >= 0) ^ (denominator >= 0);
        long num = numerator, dem = denominator;
        num = abs(num), dem = abs(dem);
        res = to_string(num / dem);
        long remain = num % dem;
        if(neg && (num / dem != 0 || remain)) res = '-' + res;
        unordered_map<int, int> m;
        while(remain && !m.count(remain)) {
            m.emplace(remain, right.size());
            remain *= 10;
            int t = remain / dem;
            right += to_string(t);
            remain = remain % dem;
        }
        
        if(!right.empty()) {
            res += '.';
            if(remain) {
                int idx = m[remain];
                res += right.substr(0, idx) + '(' + right.substr(idx) + ')';
            } else {
                res += right;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.fractionToDecimal(2, 319)<<endl;
}