#include "header.h"

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        for(const auto& edge : edges)
        {
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }

        vector<int> count(N, 0);
        vector<int> res(N, 0);

        unordered_set<int> visited;
        dfs(0, m, count, res, visited);

        visited.clear();
        dfs2(0, m, count, res, visited, N);

        return res;
    }

    void dfs(int root, unordered_map<int, unordered_set<int>>& m, vector<int>& count, vector<int>& res,
             unordered_set<int>& visited)
    {
        visited.insert(root);
        for(int i : m[root])
        {
            if(visited.find(i) == visited.end())
            {
                dfs(i, m, count, res, visited);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        }
        count[root] += 1;
    }

    void dfs2(int root, unordered_map<int, unordered_set<int>>& m, vector<int>& count, vector<int>& res,
             unordered_set<int>& visited, int N)
    {
        visited.insert(root);
        for(int i : m[root])
        {
            if(visited.find(i) == visited.end())
            {
                res[i] = res[root] - count[i] + N - count[i];
                dfs2(i, m, count, res, visited, N);
            }
        }
    }
};

int main()
{
    Solution s;
    /*vector<vector<int>> a {{0,1},{0,2},{2,3},{2,4},{2,5}};
    const auto& res = s.sumOfDistancesInTree(6, a);*/
    vector<vector<int>> a {{2,3},{0,3},{4,1},{4,3}};
    const auto& res = s.sumOfDistancesInTree(5, a);
    for(int i : res)
        std::cout<<i<<" ";
    std::cout<<endl;
}
