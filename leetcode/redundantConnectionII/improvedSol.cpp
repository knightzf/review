#include "header.h"

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> childMap;
        vector<int> dupParents;
        for(int i = 0, n = edges.size(); i < n; ++i)
        {
            const auto& p = edges[i];
            if(childMap.count(p[1]))
            {
                dupParents = {childMap[p[1]], i};
                break;
            }
            childMap[p[1]] = i;
        }

        if(!dupParents.empty())
        {
            auto r = impl(edges, dupParents[1]);
            if(r.empty()) return edges[dupParents[1]];
            return edges[dupParents[0]];
        }

        return impl(edges, -1);        
    }

    vector<int> impl(vector<vector<int>>& edges, int idx)
    {
        unordered_map<int, int> parent;
        for(int i = 0, n = edges.size(); i < n; ++i)
        {
            if(i == idx) continue;
            const auto& p = edges[i];
            int a = p[0];
            int b = p[1];
            
            if(parent.count(a) && parent.count(b))
            {
                int parentA = getParent(a, parent);
                int parentB = getParent(b, parent);
                if(parentA == parentB)
                {
                    return p;
                }
                parent[parentB] = parentA;
            }
            else if(parent.count(a))
            {
                parent[b] = parent[a];
            }
            else
            {
                parent[a] = a;
                parent[b] = a;
            }
        }
        return {};
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
    vector<vector<int>> a{{4,2},{1,5},{5,2},{5,3},{2,4}};
    //vector<vector<int>> a{{2,1},{3,1},{4,2},{1,4}};
    //vector<vector<int>> a{{3,4},{4,1},{1,2},{2,3},{5,1}};
    auto r = s.findRedundantDirectedConnection(a);
    cout<<"res "<<r[0]<<" "<<r[1]<<endl;
}
