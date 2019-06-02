#include "header.h"

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(n + 1);
        dp[0] = {0};
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(!dp[j].empty() && m.count(s.substr(j, i - j))) {
                    dp[i].push_back(j);
                }
            }
        }

        vector<string> res;
        function<void(int, const std::string&)> dfs = [&](int idx, const std::string& t)
        {
            if(idx == 0) {
                res.emplace_back(t);
                return;
            }

            for(int prevIdx : dp[idx]) {
                string tt = s.substr(prevIdx, idx - prevIdx) + (t.empty() ? "" : " ") + t;
                dfs(prevIdx, tt);
            }
        };
        dfs(n, "");
        return res;
    }
};

int main()
{
    Solution s;
    
}