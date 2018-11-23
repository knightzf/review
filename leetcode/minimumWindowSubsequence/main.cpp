#include "header.h"

class Solution {
public:
    string minWindow(string S, string T) {
        vector<set<int>> v(26);
        for(int i = 0, n = S.size(); i < n; ++i)
        {
            v[S[i] - 'a'].insert(i);
        }

        string res;
        for(int startIdx : v[T[0] - 'a'])
        {
            int endIdx = startIdx;
            bool found = true;
            for(int j = 1, n = T.size(); j < n; ++j)
            {
                auto iter = v[T[j] - 'a'].upper_bound(endIdx);
                if(iter != v[T[j] - 'a'].end())
                {
                    endIdx = *iter;
                }
                else
                {
                    found = false;
                    break;
                }
            }
            if(found)
            {
                if(res.empty() || (endIdx - startIdx + 1 < res.size()))
                {
                    res = S.substr(startIdx, endIdx - startIdx + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
