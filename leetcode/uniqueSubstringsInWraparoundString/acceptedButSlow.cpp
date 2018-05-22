#include "header.h"

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> cnt(26, 0); //num of substrings from i
        vector<int> dp(n, 0); //num of valid substrings end at i
        for(int i = 0; i < n; ++i)
        {
            if(i != 0 && isnext(p[i], p[i - 1]))
            {
                dp[i] = dp[i - 1] + 1;
                for(int j = dp[i] - 1; j >= 0; --j)
                {
                    cnt[p[i - j] - 'a'] = max(cnt[p[i - j] - 'a'], j + 1);
                }
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
