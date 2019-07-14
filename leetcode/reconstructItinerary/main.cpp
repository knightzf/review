#include "header.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, map<string, int>> m;
        for(const auto& v : tickets) {
            ++m[v[0]][v[1]];
        }
        vector<string> res;
        vector<string> t{"JFK"};
        function<bool(const string&)> dfs = [&](const string& city) {
            //for(auto i : t) cout<<i<<" "; cout<<endl;
            if(t.size() == n + 1) {
                res = t;
                return true;
            }
            for(auto& p : m[city]) {
                if(p.second > 0) {
                    t.emplace_back(p.first);
                    --p.second;
                    if(dfs(p.first)) return true;
                    t.pop_back();
                    ++p.second;
                }
            }
            return false;
        };
        dfs("JFK");
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> a{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    s.findItinerary(a);
}