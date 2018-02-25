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
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        auto tgt = std::make_pair(target[0], target[1]);
        int dist = shortestDistance(std::make_pair(0, 0), tgt);
        //std::cout<<"dist "<<dist<<std::endl;
        for(auto& g : ghosts)
        {
            int r = shortestDistance(std::make_pair(g[0], g[1]), tgt);
            //std::cout<<"r "<<r<<std::endl;
            if(r <= dist)
            {
                return false;
            }
        }

        return true;
    }

    int shortestDistance(const std::pair<int, int>& src, const std::pair<int, int>& tgt)
    {
        static vector<int> diff = {0, 1, 0, -1, 0};

        std::set<std::pair<int, int>> visited;
        visited.insert(src);

        std::queue<std::pair<int, int>> q;
        q.push(src);

        int qsize = q.size();
        int steps = 0;
        while(!q.empty())
        {
            for(int j = 0; j < qsize; ++j)
            {
                const auto& t = q.front();
                if(t == tgt) return steps;

                for(int i = 0; i < diff.size() - 1; ++i)
                {
                    auto p = t;
                    p.first += diff[i];
                    p.second += diff[i + 1];
                    if(visited.find(p) == visited.end())
                    {
                        visited.insert(p);
                        q.push(p);
                    }
                }

                q.pop();
            }
            qsize = q.size();
            ++steps;
        }

        return -1;
    }
};

int main() {
    Solution s;
    {
        vector<vector<int>> a{{1, 0}, {0,3}};
        vector<int> tgt{0, 1};
        std::cout<<s.escapeGhosts(a, tgt)<<std::endl;
    }

    {
        vector<vector<int>> a{{1, 0}};
        vector<int> tgt{2, 0};
        std::cout<<s.escapeGhosts(a, tgt)<<std::endl;
    }
    {
        vector<vector<int>> a{{2, 0}};
        vector<int> tgt{1, 0};
        std::cout<<s.escapeGhosts(a, tgt)<<std::endl;
    }
}
