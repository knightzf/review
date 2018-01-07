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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if(n == 0) return 0;

        std::set<char> charSet;
        vector<int> dp(n, 0);
        dp[0] = 1;
        charSet.insert(s[0]);
        int maxLen = 1;

        for(int i = 1; i < n; ++i)
        {
            char c = s[i];
            if(charSet.size() < 2 || charSet.find(c) != charSet.end())
            {
                charSet.insert(c);
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                charSet.clear();

                int len = 0;
                for(int j = i; j > i - dp[i - 1]; --j)
                {
                    charSet.insert(s[j]);
                    if(charSet.size() <= 2)
                    {
                        ++len;
                    }
                    else
                    {
                        charSet.erase(s[j]);
                        break;
                    }
                }

                dp[i] = len;
            }

            //std::cout<<dp[i]<<std::endl;
            maxLen = std::max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    std::cout<<s.lengthOfLongestSubstringTwoDistinct("eceba")<<std::endl;
}
