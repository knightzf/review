#include "header.h"

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return impl(node, m);
    }

    UndirectedGraphNode *impl(UndirectedGraphNode *node,
                                    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m)
    {
        m[node] = new UndirectedGraphNode(node->label);

        UndirectedGraphNode* newNode = m[node];
        for(auto* n : node->neighbors)
        {
            if(m.find(n) == m.end())
            {
                m[n] = impl(n, m);
            }
            newNode->neighbors.push_back(m[n]);
        }

        return newNode;
    }
};

int main()
{
    Solution s;
}
