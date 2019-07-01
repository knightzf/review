#include "header.h"

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        unordered_map<int, int> parent;
        vector<int> res;
        int cnt = 0;
        static vector<int> diff{-1, 0, 1, 0, -1};
        function<int(int)> findParent = [&](int i) {
            while(parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };
        for(const auto& p : positions) {
            int i = p[0], j = p[1], key = n * i + j;
            if(!parent.count(key)) {
                parent[key] = key;
                ++cnt;
                for(int k = 0; k < 4; ++k) {
                    int x = i + diff[k], y = j + diff[k + 1], newKey = x * n + y;
                    
                    if(x >= 0 && x < m && y >= 0 && y < n && parent.count(newKey)) {
                        int pa = findParent(key);
                        int pb = findParent(newKey);
                        if(pa != pb) {
                            parent[pa] = pb;
                            --cnt;
                        }
                    }
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}