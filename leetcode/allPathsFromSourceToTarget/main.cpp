#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        if(n == 0) return res;

        vector<int> path{0};
        impl(graph, path, n, res, 0);

        return res;
    }

    void impl(vector<vector<int>>& graph, vector<int>& path, int n, vector<vector<int>>& res, int node)
    {
        if(node == n - 1) res.push_back(path);

        for(const auto& next : graph[node])
        {
            path.push_back(next);
            impl(graph, path, n, res, next);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> a{
        {1, 2},
        {3},
        {3},
        {}
    };
    const auto& r = s.allPathsSourceTarget(a);
    for(const auto& v : r)
    {
        for(int i : v)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }

}
