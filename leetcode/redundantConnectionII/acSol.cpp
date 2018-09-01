#include "header.h"

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> childMap;
        vector<vector<int>> dupParents;
        for(auto& p : edges)
        {
            if(childMap.count(p[1]))
            {
                dupParents.push_back({childMap[p[1]], p[1]});
                dupParents.push_back(p);
            }
            childMap[p[1]] = p[0];
        }

        if(!dupParents.empty())
        {
            auto r = impl(edges, dupParents[1]);
            if(r.empty()) return dupParents[1];
            return dupParents[0];
        }

        return impl(edges, {});        
    }

    vector<int> impl(vector<vector<int>>& edges, const vector<int>& t)
    {
        unordered_map<int, int> parent;
        for(auto& p : edges)
        {
            if(p == t) continue;
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
