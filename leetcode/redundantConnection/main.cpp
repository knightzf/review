#include "header.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> parent;
        for(auto& v : edges)
        {
            int a = min(v[0], v[1]);
            int b = max(v[0], v[1]);
            if(parent.count(a) && parent.count(b))
            {
                int parentA = getParent(a, parent);
                int parentB = getParent(b, parent);
                if(parentA == parentB)
                {
                    return {a, b};
                }
                else
                {
                    parent[max(parentA, parentB)] = min(parentA, parentB);
                }
            }
            else if(parent.count(a))
            {
                parent[b] = parent[a];
            }
            else if(parent.count(b))
            {
                parent[a] = parent[b];
            }
            else
            {
                parent[a] = a;
                parent[b] = a;
            }
        }
    }

    int getParent(int i, unordered_map<int, int>& parent)
    {
        while(parent[i] != parent[parent[i]])
        {
            parent[i] = parent[parent[i]];
        }
        return parent[i];
    }
};

int main() {
    Solution s;
}
