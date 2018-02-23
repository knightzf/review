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

        std::unordered_map<int, std::unordered_set<int>> m;
        for(const auto& p : edges)
        {
            m[p.first].insert(p.second);
            m[p.second].insert(p.first);
        }

        vector<bool> visited(n, false);

        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(visited[i] == false)
            {
                ++cnt;

                std::queue<int> q;
                q.push(i);

                while(!q.empty())
                {
                    int t = q.front();
                    visited[t] = true;
                    q.pop();

                    if(m.find(t) != m.end())
                    {
                        const auto& s = m[t];
                        for(auto t : s)
                        {
                            if(visited[t] == false)
                            {
                                q.push(t);
                            }
                        }
                    }
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
}
