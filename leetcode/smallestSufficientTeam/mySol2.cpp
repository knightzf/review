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
        unordered_map<int, vector<int>> mm{{0, {}}};
        for(int i = 0; i < cnt; ++i) {
            unordered_map<int, vector<int>> t;
            for(const auto& pp : mm) {
                int x = pp.first | p[i];
                if(!mm.count(x)) {
                    if(!t.count(x) || t[x].size() > pp.second.size() + 1) {
                        t[x] = pp.second;
                        t[x].push_back(i);
                    }
                }
                else if(mm[x].size() > pp.second.size() + 1) {
                    mm[x] = pp.second;
                    mm[x].push_back(i);
                }
            }
            for(const auto& pp : t) mm.emplace(pp);
        }
        return mm[target];
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
