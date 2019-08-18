#include "header.h"

class Solution {
public:
    int shortestWay(string source, string target) {
        int m = source.size(), n = target.size();
        vector<vector<int>> v(26);
        for(int i = 0; i < m; ++i)
            v[source[i] - 'a'].push_back(i);
        int res = 0;
        for(int i = 0; i < n; ++res) {
            int j = i, lastIdx = -1;
            while(j < n) {
                if(v[target[j] - 'a'].empty()) return -1;
                auto& t = v[target[j] - 'a'];
                auto iter = upper_bound(t.begin(), t.end(), lastIdx);
                if(iter != t.end()) {
                    lastIdx = *iter;
                    ++j;
                } else break;
            }
            i = j;
        }
        return res;
    }
};

int main()
{
    Solution s;
}