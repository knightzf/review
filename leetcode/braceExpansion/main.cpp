#include "header.h"

class Solution {
public:
    vector<string> expand(string S) {
        vector<string> res{""};
        stack<vector<string>> s;

        for(int i = 0, n = S.size(); i < n; ++i) {
            if(S[i] == '{') {
                s.push(res);
                res.clear();
                res.push_back("");
            } else if(S[i] == '}') {
                vector<string> t;
                for(const auto& a : s.top()) {
                    for(const auto& b : res) {
                        t.push_back(a + b);
                    }
                }
                s.pop();
                swap(res, t);
            } else if(S[i] == ',') {
                res.push_back("");
            } else {
                int j = i;
                while(j < n && isalpha(S[j])) ++j;
                if(res.back().empty()) res.back() = S.substr(i, j - i);
                else for(auto& s : res) {
                    s += S.substr(i, j - i);
                }
                i = j - 1;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    //Solution s;
}