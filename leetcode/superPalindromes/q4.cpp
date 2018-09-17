#include "header.h"

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int len1 = max((int)L.size() / 2, 1);
        int len2 = R.size() / 2 + 1;

        auto check = [&](const std::string& p)
        {
            long long y = stoll(p);
            long long yy = y * y;
            if(ispalin(yy) && yy >= stoll(L) && yy <= stoll(R))
            {
                //cout<<y<<" "<<yy<<endl;
                return true;
            }
            return false;
        };
        int res = 0;
        //cout<<len1<<" "<<len2<<endl;
        for(int len = len1; len <= len2; ++len)
        {
            if(len == 1)
            {
                for(int k = 0; k < 10; ++k)
                {
                    string p = to_string(k);
                    if(check(p)) ++ res;
                }
                continue;
            }
            bool even = len % 2 == 0;
            int half = len / 2;
            //cout<<(int)pow(10, half - 1)<<" "<<pow(10, half)<<endl;
            for(int j = pow(10, half - 1), t = pow(10, half); j < t; ++j)
            {
                string x = to_string(j);
                string y = x; reverse(y.begin(), y.end());
                if(even)
                {
                    string p = x + y;
                    if(check(p)) ++ res;
                }
                else
                {
                    for(int k = 0; k < 10; ++k)
                    {
                        string p = x + to_string(k) + y;
                        if(check(p)) ++ res;
                    }
                }
            }
        }
        return res;
    }

    bool ispalin(long long t)
    {
        string s = to_string(t);
        int i = 0, j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main()
{
    Solution s;
    //cout<<s.superpalindromesInRange("4", "1000")<<endl;
    //cout<<s.superpalindromesInRange("1", "213")<<endl;
    cout<<s.superpalindromesInRange("1", "19028")<<endl;
    //cout<<s.superpalindromesInRange("398904669", "13479046850")<<endl;
}
