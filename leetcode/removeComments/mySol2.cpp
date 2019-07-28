#include "header.h"

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool inblock = false;
        string t;
        for(int i = 0, n = source.size(), k = 0, lastblock = 0; i < n; ++i) {
            const auto& s = source[i];
            for(int j = 0, m = s.size(); j < m; ++j, ++k) {
                if(!inblock && s[j] == '/' && j + 1 < m && s[j + 1] == '/') {
                    break;
                } else if(!inblock && s[j] == '/' && j + 1 < m && s[j + 1] == '*') {
                    inblock = true;
                    lastblock = k;
                } else if(inblock && s[j] == '/' && j > 0  && s[j - 1] == '*' && lastblock + 2 < k) {
                    inblock = false;
                } else if(!inblock) {
                    t += s[j];
                }
            }
            if(!inblock && t.size()) { res.emplace_back(t); t.clear(); }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}