#include "header.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        int n = words.size();
        for(int i = 0; i < n; ++i) m[words[i]] = i;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= words[i].size(); ++j) {
                const string& str1 = words[i].substr(0, j);
                const string& str2 = words[i].substr(j);
                if(ispalin(str1)) {
                    auto t = str2;
                    reverse(t.begin(), t.end());
                    auto iter = m.find(t);
                    if(iter != m.end() && iter->second != i) {
                        res.emplace_back(vector<int>{iter->second, i});
                    }
                }
                if(!str2.empty() && ispalin(str2)) {
                    auto t = str1;
                    reverse(t.begin(), t.end());
                    auto iter = m.find(t);
                    if(iter != m.end() && iter->second != i) {
                        res.emplace_back(vector<int>{i, iter->second});
                    }
                }
            }
        }
        return res;
    }

    bool ispalin(const string& str) {
        int i = 0, j = str.size() - 1;
        while(i < j)
            if(str[i++] != str[j--]) return false;
        return true;
    }
};

int main()
{
    Solution s;
}