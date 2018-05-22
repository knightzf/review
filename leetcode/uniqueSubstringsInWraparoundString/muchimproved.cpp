#include "header.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> cnt(26, 0); //num of substrings from a, b, c..
        vector<int> dp(n, 0); //num of valid substrings from at i

        for(int i = n - 1; i >= 0; --i)
        {
            if(i != n - 1 && isnext(p[i + 1], p[i]))
            {
                dp[i] = dp[i + 1] + 1;
                cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], dp[i]);
            }
            else
            {
                dp[i] = 1;
                cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], 1);
            }
        }

        return accumulate(cnt.begin(), cnt.end(), 0);
    }
private:
    bool isnext(char b, char a)
    {
        return (b - 'a') == ((a - 'a' + 1) % 26);
    }
};

int main()
{
    Solution s;
    cout<<s.findSubstringInWraproundString("cac")<<endl;
    cout<<s.findSubstringInWraproundString("zab")<<endl;
}
