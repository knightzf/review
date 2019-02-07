#include "header.h"

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        int mod = 1e9 + 7;
        unordered_map<char, set<int>> m;
        for(int i = 0; i < n; ++i)
        {
            m[S[i]].insert(i);
        }

        vector<vector<long>> dp(n, vector<long>(n, 0));
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        for(int len = 1; len < n; ++len)
        {
            for(int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                char c = S[j];
                auto left = m[c].lower_bound(i);
                if(left == m[c].end() || *left >= j)
                {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
                else
                {
                    auto right = m[c].find(j);
                    --right;
                    if(left == right){
                        dp[i][j] = dp[i][j - 1] + dp[*left + 1][j - 1] + 1;
                    } 
                    else
                    {
                        dp[i][j] = mod + dp[i][j - 1] - (dp[*left + 1][*right - 1] + 1);
                        dp[i][j] += dp[*left + 1][j - 1] + 1;
                    }
                }
                dp[i][j] %= mod;
            }
        }

        return dp[0][n - 1];            
    }
};

int main()
{
    Solution s;
    /*cout<<s.countPalindromicSubsequences("bccb")<<endl;
    cout<<s.test("bccb")<<endl;
    cout<<s.countPalindromicSubsequences("aabaa")<<endl;
    cout<<s.test("aabaa")<<endl;
    cout<<s.countPalindromicSubsequences("dbcbaaacdcbabcbddaac")<<endl;
    cout<<s.test("dbcbaaacdcbabcbddaac")<<endl;*/
    cout<<s.countPalindromicSubsequences("dddcabadcbabccdadccbcabcdacdadcbbbcadaabcddccbcadaddbdbdacbcccddabbbcbcdccdaadabadacacbdbbbadcdaaabb")<<endl;
}