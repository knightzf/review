#include "header.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        function<Node*(Node*)> f = [&](Node* node)
        {
            if(!node) return node;
            if(!m.count(node)) {
                Node* newNode = new Node(node->val, nullptr, nullptr);
                m.emplace(node, newNode);
                newNode->next = f(node->next);
                newNode->random = f(node->random);                
            }
            return m[node];
        };
        return f(head);
    }
};

int main()
{
    Solution s;
    
}