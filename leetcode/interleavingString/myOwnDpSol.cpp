#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        if(s3.empty())
        {
            return s1.empty() && s2.empty();
        }
        else
        {
            if(s1.empty())
            {
                return s2 == s3;
            }

            if(s2.empty())
            {
                return s1 == s3;
            }
        }

        int M = s1.size();
        int N = s2.size();
        int K = s3.size();

        std::vector<std::vector<std::vector<int>>> dp(K + 1,
            std::vector<std::vector<int>>(M + 1, std::vector<int>(N + 1, 0)));
        dp[0][0][0] = 1;

        for(int k = 1; k <= K; ++k)
        {
            for(int i = 0; i <= k && i <= s1.size(); ++i)
            {
                int j = k - i;

                if(j > s2.size())
                {
                    continue;
                }

                bool match = false;

                if(i == 0)
                {
                    match = s2[j - 1] == s3[k - 1] && dp[k - 1][i][j - 1];
                }
                else if(j == 0)
                {
                    match = s1[i - 1] == s3[k - 1] && dp[k - 1][i - 1][j];
                }
                else
                {
                    match = (s2[j - 1] == s3[k - 1] && dp[k - 1][i][j - 1]) ||
                        (s1[i - 1] == s3[k - 1] && dp[k - 1][i - 1][j]);
                }

                dp[k][i][j] = match;
            }
        }

        return dp[K][M][N];
    }
};

int main()
{
    Solution s;

    std::cout<<s.isInterleave("aacaac", "aacaaeaac", "aacaacaaeaacaac")<<std::endl;
    //return 0;
    std::cout<<s.isInterleave("aabc", "abad", "aabcabad")<<std::endl;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<std::endl;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbbaccc")<<std::endl;
    std::cout<<s.isInterleave("cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
                              "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
                              "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb")<<std::endl;

    std::cout<<s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                              "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                              "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<std::endl;

}
