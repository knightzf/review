#include "header.h"

class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        unordered_map<string, int> m;
        function<int(const std::string&)> dfs = [&](const string& s)
        {
            if(s.size() == 1) return 1;
            if(!m.count(s)) {
                int res = 0;
                for(int i = 0, n = s.size(); i < n; ++i) {
                    if(i == 0 || s[i] != s[i - 1]) {
                        res += dfs(s.substr(0, i) + s.substr(i + 1)) + 1;
                    }
                }
                m[s] = res;
            }
            return m[s];
        };

        return dfs(tiles);
    }
};

int main()
{
    Solution s;
    cout<<s.numTilePossibilities("AB")<<endl;
}
