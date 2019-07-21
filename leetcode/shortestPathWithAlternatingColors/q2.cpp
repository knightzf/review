#include "header.h"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n, -1);
        unordered_map<int, unordered_map<int, unordered_set<int>>> m;
        for(const auto& e : red_edges) {
            m[e[0]][0].insert(e[1]);
        }
        for(const auto& e : blue_edges) {
            m[e[0]][1].insert(e[1]);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(0, -1));
        int qsize = q.size();
        int steps = 0;
        set<pair<int, int>> mm;
        while(!q.empty()) {
            for(int i = 0; i < qsize; ++i) {
                const auto& p = q.front();
                if(mm.count(p)) {
                    q.pop();
                    continue;
                } else mm.insert(p);
                if(res[p.first] == -1) res[p.first] = steps;
                for(const auto& t : m[p.first]) {
                    if(t.first != p.second) {
                        for(int next : t.second) {
                            q.push(make_pair(next, t.first));
                        }
                    }
                }
                q.pop();
            }
            qsize = q.size();
            ++steps;
        }
        return res;
    }
};

int main()
{
}
