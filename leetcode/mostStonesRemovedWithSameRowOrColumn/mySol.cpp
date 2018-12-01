#include "header.h"

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> x;
        unordered_map<int, unordered_set<int>> y;
        map<vector<int>, bool> visited;
        for(auto& p : stones)
        {
            x[p[0]].insert(p[1]);
            y[p[1]].insert(p[0]);
            visited[p] = false;
        }

        int res = 0;
        function<void(const vector<int>&, int&)> dfs = [&](const vector<int>& p, int& cnt)
        {
            if(visited[p]) return;
            visited[p] = true;
            ++cnt;

            for(int i : x[p[0]])
            {
                dfs(vector<int>{p[0], i}, cnt);
            }

            for(int i : y[p[1]])
            {
                dfs(vector<int>{i, p[1]}, cnt);
            }
        };

        for(auto& p : stones)
        {
            if(visited[p] == false)
            {
                int cnt = 0;
                dfs(p, cnt);
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

