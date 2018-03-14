#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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
        vector<int> parent(n, -1);

        for(const auto& p : edges)
        {
            int p1 = findParent(parent, p.first);
            int p2 = findParent(parent, p.second);

            if(p1 == -1)
            {
                parent[p.first] = p2;
            }
            else if(p2 == -1)
            {
                parent[p.second] = p1;
            }
            else
            {
                if(p1 == p2) return false;
                parent[p1] = p2;
            }
        }

        return edges.size() == n - 1;
    }

    int findParent(vector<int>& parent, int idx)
    {
        while(parent[idx] != -1)
        {
            idx = parent[idx];
        }
        return idx;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> a{
        {0, 2},
        {2, 1},
        {1, 0}
    };
    /*vector<pair<int, int>> a{
        {0, 1},
        {2, 3},
        {1, 2}
    };
    vector<pair<int, int>> a{
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };
    vector<pair<int, int>> a{
        {0, 1},
        {1, 2},
        {2, 3},
        {1, 3},
        {1, 4}
    };*/
    std::cout<<s.validTree(3, a)<<std::endl;
}
