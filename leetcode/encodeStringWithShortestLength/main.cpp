#include "header.h"

class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));
        for(int len = 0; len < n; ++len)
        {
            for(int i = 0; i < n - len; ++i)
            {
                int j = i + len;
                const string& subS = s.substr(i, len + 1);
                dp[i][j] = subS;

                if(len > 4)
                {
                    for(int k = i; k < j; ++k)
                    {
                        if((dp[i][k].size() + dp[k + 1][j].size()) < dp[i][j].size())
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }

                for(int k = 0; k < len + 1; ++k)
                {
                    int sz = k + 1;
                    if((len + 1) % sz == 0)
                    {
                        const string& t = subS.substr(0, sz);
                        bool found = true;
                        for(int j = sz; j < len + 1; j += sz)
                        {
                            if(subS.substr(j, sz) != t)
                            {
                                found = false;
                                break;
                            }
                        }

                        if(found)
                        {
                            string tt = to_string((len + 1)/sz) + "[" + t + "]";
                            if(tt.size() < dp[i][j].size())
                                dp[i][j] = tt;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution s;
}
