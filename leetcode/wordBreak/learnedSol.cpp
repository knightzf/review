#include "header.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<string> m(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                if(dp[j])
                {
                    const std::string& t = s.substr(j, i - j);
                    if(m.find(t) != m.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<string> a{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    std::cout<<s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", a)<<std::endl;
}
