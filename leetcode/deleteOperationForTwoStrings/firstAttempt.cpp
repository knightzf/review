#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<set<int>> v1(26);
        for(int i = 0; i < m; ++i)
            v1[word1[i] - 'a'].insert(i);

        vector<set<int>> v2(26);
        for(int i = 0; i < n; ++i)
            v2[word2[i] - 'a'].insert(i);

        int i = 0, j = 0;
        string t;
        for(; i < m; ++i)
        {
            auto iter = v2[word1[i] - 'a'].lower_bound(j);
            if(iter != v2[word1[i] - 'a'].end())
            {
                t += word1[i];
                j = *iter + 1;
            }
        }

        int res = m + n - (int)t.size() * 2;

        t.clear();
        i = 0; j = 0;
        for(; i < n; ++i)
        {
            auto iter = v1[word2[i] - 'a'].lower_bound(j);
            if(iter != v1[word2[i] - 'a'].end())
            {
                t += word2[i];
                j = *iter + 1;
            }
        }

        res = min(res, m + n - (int)t.size() * 2);
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.minDistance("sea", "eat")<<endl;
}
