#include "header.h"

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> p(m * n, -1);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int idx = n * i + j;
                //cout<<i<<" "<<j<<" "<<idx<<endl;
                if(grid[i][j]) {
                    int p1 = -1, p2 = -1;
                    if(i > 0 && grid[i - 1][j]) {
                        p1 = getParent(p, n * (i - 1) + j);
                    }

                    if(j > 0 && grid[i][j - 1]) {
                        p2 = getParent(p, n * i + j - 1);
                    }
                    
                    if(p1 != -1 && p2 != -1) {
                        p[idx] = min(p1, p2);
                        p[max(p1, p2)] = min(p1, p2);
                    }
                    else if(p1 != -1) {
                        p[idx] = p1;
                    }
                    else if(p2 != -1) {
                        p[idx] = p2;
                    }
                    else {
                        p[idx] = idx;
                    }
                }
            }
        }

        //for(int i = 0; i < m * n; ++i)
        //cout<<p[i]<<endl;
        unordered_map<int, vector<int>> islands;
        for(int i = 0; i < m * n; ++i)
        {
            if(p[i] != -1)
            {
                int pp = getParent(p, i);
                islands[pp].push_back(i);
            }
        }

        set<vector<pair<int, int>>> s;
        for(auto& p : islands)
        {
            vector<pair<int, int>> t;
            auto& v = p.second;
            int x = v[0] / n;
            int y = v[0] % n;
            for_each(v.begin(), v.end(), [&](int& idx){ 
                t.emplace_back(make_pair(idx / n - x, idx % n - y));
            });
            s.insert(t);
        }
        return s.size();
    }

    int getParent(vector<int>& p, int idx) {
        while(p[idx] != p[p[idx]]) {
            p[idx] = p[p[idx]];
        }
        return p[idx];
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    //vector<vector<int>> a{{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
    cout<<s.numDistinctIslands(a)<<endl;
}
