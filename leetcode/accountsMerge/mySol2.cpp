#include "header.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int, int> p;
        int n = accounts.size();
        for(int i = 0; i < n; ++i) p[i] = i;
        auto getParent = [&](int i) {
            while(p[i] != i) {
                p[i] = p[p[i]];
                i = p[i];
            }
            return i;
        };
        unordered_map<string, int> mm;
        for(int i = 0, n = accounts.size(); i < n; ++i) {
            for(int j = 1, m = accounts[i].size(); j < m; ++j) {
                const auto& email = accounts[i][j];
                int pa = getParent(i);
                auto iter = mm.find(email);
                if(iter != mm.end()) {
                    int pb = getParent(iter->second);
                    if(pa != pb) {
                        p[pa] = pb;
                        pa = pb;
                    }
                }
                mm[email] = pa;
            }
        }
        unordered_map<int, set<string>> t;
        for(const auto& p : mm) {
            int pa = getParent(p.second);
            if(!t.count(pa)) {
                t[pa] = {accounts[pa][0], p.first};
            } else {
                t[pa].insert(p.first);
            }
        }
        vector<vector<string>> res;
        for(const auto& p : t) {
            res.emplace_back(vector<string>(p.second.begin(), p.second.end()));
        }
        return res;
    }
};

int main()
{
    //Solution s;
}