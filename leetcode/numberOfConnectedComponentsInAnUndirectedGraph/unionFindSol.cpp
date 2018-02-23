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
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if(n == 0) return 0;
        if(edges.empty()) return n;

        vector<int> roots(n, 0);
        for(int i = 0; i < n; ++i) roots[i] = i;

        for(const auto& p : edges)
        {
            int root1 = findRoot(roots, p.first);
            int root2 = findRoot(roots, p.second);
            if(root1 != root2)
            {
                roots[root1] = root2;
                --n;
            }
        }

        return n;
    }

    int findRoot(vector<int>& roots, int idx)
    {
        while(roots[idx] != idx)
        {
            roots[idx] = roots[roots[idx]];
            idx = roots[idx];
        }

        return idx;
    }
};

int main() {
    Solution s;
}
