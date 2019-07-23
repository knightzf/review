#include "header.h"

class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        if(len == 1) return to_string(stoi(n) - 1);
        vector<string> v{string(len - 1, '9')};
        string t(len + 1, '0');
        t[0] = '1', t.back() = '1';
        v.push_back(t);
        auto prefix = stoll(n.substr(0, (1 + len) / 2));
        for(long i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (len & 1), p.rend());
            if(pp != n) v.push_back(pp);
        }
        string res = v[0];
        long long diff = llabs(stoll(v[0]) - stoll(n));
        for(int i = 1; i < v.size(); ++i) {
            long long t = llabs(stoll(v[i]) - stoll(n));
            if(t < diff || (t == diff && stoll(v[i]) < stoll(res))) {
                res = v[i];
                diff = t;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.nearestPalindromic("99")<<endl;
}