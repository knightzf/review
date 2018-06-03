#include "header.h"

class Solution {
private:
    int res;
    int n;
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        if(n == 1) return 0;
        if(n == 2) return 1;

        res = INT_MAX;
        unordered_set<int> nodes;
        vector<unordered_set<int>> edges(n);
        for(int i = 0; i < n; ++i)
        {
            edges[i].insert(graph[i].begin(), graph[i].end());
        }

        for(int i = 0; i < n; ++i)
        {
            nodes.clear();
            nodes.insert(i);
            impl(edges, i, nodes, 0);
        }

        return res;
    }

    void impl(vector<unordered_set<int>>& edges, int idx, unordered_set<int>& nodes, int steps)
    {
        //cout<<"idx "<<idx<<" "<<steps<<endl;
        if(steps > res) return;
        if(nodes.size() == n)
        {
            //cout<<"got all "<<steps<<endl;
            res = min(res, steps);
            return;
        }

        auto neighbors = edges[idx];
        for(auto next : neighbors)
        {
            bool newNode = nodes.find(next) == nodes.end();
            nodes.insert(next);
            edges[idx].erase(next);
            impl(edges, next, nodes, steps + 1);
            edges[idx].insert(next);
            if(newNode) nodes.erase(next);
        }
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> a{{1, 2, 3},{0},{0},{0}};
    vector<vector<int>> a{{1},{0,2,4},{1,3,4},{2},{1,2}};
    cout<<s.shortestPathLength(a)<<endl;
}
