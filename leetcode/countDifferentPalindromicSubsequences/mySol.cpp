#include "header.h"

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        function<int(int, int)> f = [&](int startIdx, int endIdx)
        {
            if(dp[startIdx][endIdx] == -1)
            {
                long cnt = 0;

                for(int i = 0; i < 4; ++i)
                {
                    char c = 'a' + i;
                    const auto& str = S.substr(startIdx, endIdx - startIdx);
                    int idx = str.find(c);
                    if(idx != -1)
                    {
                        int lastIdx = str.find_last_of(c);
                        if(lastIdx != -1 && lastIdx != idx)
                        {
                            cnt += f(startIdx + idx + 1, startIdx + lastIdx);
                        }
                        ++cnt;
                    }
                }

                //std::cout<<startIdx<<" "<<endIdx<<" "<<(cnt + 1) % mod<<endl;
                dp[startIdx][endIdx] = (cnt + 1) % mod;
            }
            
            return dp[startIdx][endIdx];   
        };

        return f(0, n) - 1;
    }
};

int main()
{
    Solution s;
    //cout<<s.countPalindromicSubsequences("bccb")<<endl;
    //cout<<s.countPalindromicSubsequences("aabaa")<<endl;
    cout<<s.countPalindromicSubsequences("dbcbaaacdcbabcbddaac")<<endl;
    //cout<<s.countPalindromicSubsequences("cdcbabcd")<<endl;
}