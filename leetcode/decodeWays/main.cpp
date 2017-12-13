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
    int numDecodings(string s)
    {
        int n = s.size();
        if(n == 0)
        {
            return 0;
        }

        std::vector<int> dp(n, 0);
        for(int i = 0; i < s.size(); ++i)
        {
            int v = s[i] - '0';

            if(i == 0)
            {
                if(v == 0)
                {
                    return 0;
                }

                dp[i] = 1;
            }
            else
            {
                int cnt = 0;

                if(v == 0)
                {
                    int t = s[i - 1] - '0';
                    if(t != 1 && t != 2)
                    {
                        return 0;
                    }

                    cnt = i >= 2 ? dp[i - 2] : 1;
                }
                else
                {
                    cnt = dp[i - 1];

                    int num = v + (s[i - 1] - '0') * 10;
                    if(10 < num && num <= 26)
                    {
                        if(i >= 2)
                        {
                            cnt += dp[i - 2];
                        }
                        else
                        {
                            ++cnt;
                        }
                    }
                }

                dp[i] = cnt;
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    //std::cout<<s.numDecodings("123")<<std::endl;
    std::cout<<s.numDecodings("12120")<<std::endl;
}
