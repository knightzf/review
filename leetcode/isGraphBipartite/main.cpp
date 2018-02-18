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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n < 2) return false;

        std::unordered_set<int> gp1;
        std::unordered_set<int> gp2;

        for(int i = 0; i < n; ++i)
        {
            bool group1 = false, group2 = false;
            if(gp1.find(i) == gp1.end() && gp2.find(i) == gp2.end())
            {
                gp1.insert(i);
                group1 = true;
            }
            else if(gp1.find(i) != gp1.end())
            {
                group1 = true;
            }
            else if(gp2.find(i) != gp2.end())
            {
                group2 = true;
            }

            for(auto j : graph[i])
            {
                if(group1)
                {
                    if(gp1.find(j) != gp1.end()) return false;
                    gp2.insert(j);
                }
                else
                {
                    if(gp2.find(j) != gp2.end()) return false;
                    gp1.insert(j);
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
}
