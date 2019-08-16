#include "header.h"

class Solution {
public:
    vector<string> braceExpansionII(string exp) {
        int n = exp.size();
        stack<vector<unordered_set<string>>> stk;
        vector<unordered_set<string>> res;
        for(int i = 0; i < n; ++i) {
            char c = exp[i];
            if(c == ',') {
                res.push_back({});
            } else if(c == '{') {
                stk.push(res);
                res.clear();
            } else if(c == '}') {
                unordered_set<string> t;
                for(const auto& s : res)
                    for(const auto& str : s) t.insert(str);
                res = stk.top();
                stk.pop();
                if(res.empty()) res.push_back({});
                res.back() = combine(res.back(), t);
            } else {
                int j = i;
                while(j < n && isalpha(exp[j])) ++j;
                const auto& s = exp.substr(i, j - i);
                if(res.empty()) res.push_back({});
                res.back() = combine(res.back(), unordered_set<string>{s});
                i = j - 1;
            }
        }
        set<string> t;
        for(const auto& s : res)
            for(const auto& str : s) t.insert(str);
        return vector<string>(t.begin(), t.end());
    }

    unordered_set<string> combine(const unordered_set<string>& a, const unordered_set<string>& b) {
        if(a.empty()) return b;
        unordered_set<string> res;
        for(const auto& as : a) {
            for(const auto& bs : b) {
                res.insert(as + bs);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}