#include "header.h"

class Solution {
private:
    string w1;
    string w2;
    int m, n;
public:
    int minDistance(string word1, string word2) {
        w1 = word1; w2 = word2;
        int m = word1.size(), n = word2.size();

        vector<set<int>> v1(26);
        for(int i = 0; i < m; ++i)
            v1[word1[i] - 'a'].insert(i);

        vector<set<int>> v2(26);
        for(int i = 0; i < n; ++i)
            v2[word2[i] - 'a'].insert(i);

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxSize = impl(v1, v2, dp, m, n, 0, 0);
        return m + n - 2 * maxSize;
    }

    int impl(vector<set<int>>& v1, vector<set<int>>& v2, vector<vector<int>>& dp,
             int m, int n, int i, int j)
    {
        if(i == m || j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int res = impl(v1, v2, dp, m, n, i + 1, j);
        if(v2[w1[i] - 'a'].size() != 0)
        {
            auto iter = v2[w1[i] - 'a'].lower_bound(j);
            if(iter != v2[w1[i] - 'a'].end())
            {
                res = max(res, 1 + impl(v1, v2, dp, m, n, i + 1, *iter + 1));
            }
        }

        dp[i][j] = res;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.minDistance("sea", "eat")<<endl;
    cout<<s.minDistance("abcdxabcde", "abcdeabcdx")<<endl;
}
