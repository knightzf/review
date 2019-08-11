#include "header.h"

class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        vector<int> lastIdx(26, 0), firstIdx(26, 0);
        for(int i = 0; i < n; ++i) lastIdx[text[i] - 'a'] = i;
        for(int i = n - 1; i >= 0; --i) firstIdx[text[i] - 'a'] = i;
        int res = 0;
        for(int i = 0; i < n;) {
            char c = text[i];
            int j = i;
            while(j < n && text[j] == c) ++j;
            if(j == n) {
                res = max(res, j - i);
                break;
            }
            int diffIdx = j++;
            if(j < n && text[j] == c) {
                while(j < n && text[j] == c) ++j;
            }
            cout<<i<<" "<<j<<endl;
            bool hasit = lastIdx[c - 'a'] > j || firstIdx[c - 'a'] < i;
            res = max(res, j - i - (hasit ? 0 : 1));
            i = diffIdx;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.maxRepOpt1("bbababaaaa")<<endl;
}

