#include "header.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        function<Node*(Node*)> clone = [&](Node* n)
        {
            if(!n) return n;
            if(!m.count(n)) {
                Node* newNode = new Node();
                m.emplace(n, newNode);
                newNode->val = n->val;
                for(auto* p : n->neighbors) {
                    newNode->neighbors.emplace_back(clone(p));
                }                
            }
            return m[n];
        };
        return clone(node);
    }
};

int main()
{
    Solution s;
    
}