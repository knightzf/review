#include "header.h"

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> parent(n);
        for(int i = 0; i < n; ++i) parent[i] = i;
        function<int(int)> findParent = [&](int i) {
            while(parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };
        for(const auto& v : edges) {
            int pa = findParent(v[0]);
            int pb = findParent(v[1]);
            if(pa == pb) return false;            
            parent[pa] = pb;
        }
        return true;
    }
};

int main()
{
    //Solution s;
}