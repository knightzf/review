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
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n <= 1) return true;
        if(edges.empty()) return false;

        std::unordered_map<int, std::vector<int>> links;
        for(int i = 0; i < edges.size(); ++i)
        {
            const auto& p = edges[i];
            links[p.first].push_back(p.second);
            links[p.second].push_back(p.first);
        }

        vector<bool> visited(n, false);
        if(!visit(edges[0].first, links, visited, -1)) return false;

        for(int i = 0; i < n; ++i)
        {
            if(!visited[i]) return false;
        }

        return true;
    }

    bool visit(int i, std::unordered_map<int, std::vector<int>>& links, vector<bool>& visited, int previous)
    {
        if(visited[i]) return false;

        visited[i] = true;
        const auto& neighbors = links[i];
        for(auto n : neighbors)
        {
            if(n != previous && !visit(n, links, visited, i)) return false;
        }

        return true;
    }
};

int main() {
    Solution s;
}
