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

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K)
    {
        std::map<int, std::map<int, int>> map;
        for(const auto& v : times)
        {
            map[v[0]][v[1]] = v[2];
        }

        std::vector<int> distance(N + 1, INT_MAX);

        distance[K] = 0;

        std::queue<int> q;
        q.push(K);

        while(!q.empty())
        {
            for(int n = q.size(); n > 0; --n)
            {
                std::set<int> visitedNodes;

                int node = q.front();
                q.pop();

                for(const auto& m : map[node])
                {
                    int desNode = m.first;
                    int weight = m.second;

                    if(distance[node] + weight < distance[desNode])
                    {
                        distance[desNode] = distance[node] + weight;
                        if(visitedNodes.find(desNode) == visitedNodes.end())
                        {
                            visitedNodes.insert(desNode);
                            q.push(desNode);
                        }
                    }
                }
            }
        }

        int result = -1;
        for(int i = 1; i < N + 1; ++i)
        {
            if(distance[i] == INT_MAX)
            {
                return -1;
            }
            else
            {
                result = std::max(result, distance[i]);
            }
        }

        return result;
    }
};
int main()
{
    Solution s;
}
