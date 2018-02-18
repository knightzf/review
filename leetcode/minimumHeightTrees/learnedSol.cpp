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
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        std::unordered_map<int, std::unordered_set<int>> m;
        for(auto& e : edges)
        {
            m[e.first].insert(e.second);
            m[e.second].insert(e.first);
        }

        vector<int> leaves;
        for(const auto& n : m)
        {
            if(n.second.size() == 1)
            {
                leaves.push_back(n.first);
            }
        }

        while(n > 2)
        {
            n -= leaves.size();
            vector<int> newLeaves;
            for(int i : leaves)
            {
                int j = *m[i].begin();
                m[j].erase(i);

                if(m[j].size() == 1) newLeaves.push_back(j);
            }

            leaves = newLeaves;
        }

        return leaves;
    }
};

int main() {
    Solution s;
}
