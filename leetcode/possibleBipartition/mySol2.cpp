#include "header.h"

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int n = dislikes.size();
        vector<int> color(N + 1, 0);
        unordered_map<int, unordered_set<int>> m;
        for(const auto& v : dislikes) {
            m[v[0]].insert(v[1]);
            m[v[1]].insert(v[0]);
        }

        for(const auto& p : m) {
            if(color[p.first]) continue;
            color[p.first] = 1;
            queue<int> q;
            q.push(p.first);
            while(!q.empty()) {
                int i = q.front();
                q.pop();
                for(int j : m[i]) {
                    if(color[j] == color[i]) return false;
                    if(!color[j]) {
                        color[j] = -color[i];
                        q.push(j);
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
}