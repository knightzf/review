class Solution {
public:
    void impl(const vector<vector<int>>& graph,vector<vector<int>>& res, vector<int>& path, int i, int n) {            
        if (i == n - 1) {
            res.push_back(path);
            return;
        }

        for(int j : graph[i]) {
            path.push_back(j);        
            impl(graph, res, path, j, n);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
           int n = graph.size();           
           vector<vector<int>> res;
           if (n == 0) {
               return res;
           }
           vector<int> path {0};
           impl(graph, res, path, 0, n);
           return res; 
    }
};
