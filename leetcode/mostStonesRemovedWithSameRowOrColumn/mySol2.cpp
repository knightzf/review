#include "header.h"

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> xmap, ymap;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i) {
            xmap[stones[i][0]].push_back(i);
            ymap[stones[i][1]].push_back(i);
        }
        int res = 0;

        function<int(int)> bfs = [&](int idx) {
            int res = 0;
            queue<int> q;
            q.push(idx);
            while(!q.empty()) {
                ++res;
                int i = q.front();
                q.pop();

                for(int j : xmap[stones[i][0]]) {
                    if(!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }

                for(int j : ymap[stones[i][1]]) {
                    if(!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
            return res;
        };

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                visited[i] = true;
                int cnt = bfs(i);
                res += cnt - 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
}