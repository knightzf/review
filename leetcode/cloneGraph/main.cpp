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

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if(node == nullptr) return nullptr;
        nodeMap.clear();

        return impl(node);
    }

    UndirectedGraphNode *impl(UndirectedGraphNode *node)
    {
        UndirectedGraphNode* newNode;
        if(nodeMap.find(node->label) == nodeMap.end())
        {
            newNode = new UndirectedGraphNode(node->label);
            nodeMap[node->label] = newNode;
        }
        else
        {
            newNode = nodeMap[node->label];
        }

        for(auto neighbor : node->neighbors)
        {
            UndirectedGraphNode* newNeighbor;

            if(nodeMap.find(neighbor->label) == nodeMap.end())
            {
                newNeighbor = impl(neighbor);
                newNode->neighbors.push_back(newNeighbor);
            }
            else
            {
                newNeighbor = nodeMap[neighbor->label];
                newNode->neighbors.push_back(newNeighbor);
            }
        }

        return newNode;
    }

private:
    std::unordered_map<int, UndirectedGraphNode*> nodeMap;
};

int main()
{
    Solution s;
}
