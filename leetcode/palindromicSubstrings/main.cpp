#include "header.h"

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() < 2) return s.size();
        int n = s.size();
        vector<int> dp(n, 0);
        unordered_map<char, vector<int>> m;
        vector<vector<bool>> matrix(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i)
            matrix[i][i] = true;

        dp[0] = 1;
        m[s[0]].push_back(0);
        for(int i = 1; i < n; ++i)
        {
            if(m.find(s[i]) != m.end())
            {
                int cnt = 1;
                for(int j : m[s[i]])
                {
                    if(j + 1 == i || matrix[j + 1][i - 1])
                    {
                        ++cnt;
                        matrix[j][i] = true;
                    }
                }
                dp[i] = dp[i - 1] + cnt;
            }
            else
            {
                dp[i] = dp[i - 1] + 1;
            }
            m[s[i]].push_back(i);
        }

        //for(int i : dp)
        //    std::cout<<i<<" ";
        //std::cout<<std::endl;

        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    std::cout<<s.countSubstrings("aaa")<<std::endl;
}
