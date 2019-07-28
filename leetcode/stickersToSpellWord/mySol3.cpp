#include "header.h"

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> v(n, vector<int>(26, 0));
        for(int i = 0; i < n; ++i) for(char c : stickers[i]) ++v[i][c - 'a'];
        unordered_map<string, int> dp{{"", 0}};
        function<int(const string&)> dfs = [&](const string& str) {
            if(dp.count(str)) return dp[str];
            int res = INT_MAX;
            vector<int> t(26, 0);
            for(char c : str) ++t[c - 'a'];
            for(int i = 0; i < n; ++i) {
                if (v[i][str[0] - 'a'] == 0) continue;
                string newstr;
                for(int j = 0; j < 26; ++j) {
                    if(t[j] - v[i][j] > 0)
                        newstr += string(t[j] - min(t[j], v[i][j]), 'a' + j);
                }
                int tmp = dfs(newstr);
                if(tmp != -1) res = min(res, 1 + tmp);
            }
            dp[str] = res == INT_MAX ? -1 : res;
            return dp[str];
        };
        return dfs(target);
    }
};

int main()
{
    Solution s;
    vector<string> a{"with","example","science"};
    cout<<s.minStickers(a, "thehat")<<endl;
}