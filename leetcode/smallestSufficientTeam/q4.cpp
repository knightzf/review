#include "header.h"

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int target = (1 << n) - 1;
        unordered_map<string, int> m;
        for(int i = 0; i < n; ++i) m[req_skills[i]] = i;
        int cnt = people.size();
        vector<int> p; p.reserve(cnt);
        for(const auto& v : people) {
            int t = 0;
            for(const auto& s : v) {
                t |= (1 << (m[s]));
            }
            p.push_back(t);
        }
        vector<int> res;
        vector<int> t;
        set<tuple<int, int, int>> mm;
        function<void(int, int)> dfs = [&](int idx, int state) {
            auto x = make_tuple(idx, state, t.size());
            if(mm.count(x)) return;
            mm.insert(x);
            if(!res.empty() && t.size() >= res.size()) return;
            if(state == target) {
                if(res.empty() || t.size() < res.size()) {
                    res = t;
                    return;
                }
            }
            if(idx == cnt) return;
            for(int i = idx; i < cnt; ++i) {
                if(p[i]) {
                    t.push_back(i);
                    dfs(i + 1, state | p[i]);
                    t.pop_back();
                }
            }
        };
        dfs(0, 0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"java","nodejs","reactjs"};
    vector<vector<string>> b{{"java"},{"nodejs"},{"nodejs","reactjs"}};
    const auto& r = s.smallestSufficientTeam(a, b);
    for(int i : r) cout<<i<<" ";cout<<endl;
}
