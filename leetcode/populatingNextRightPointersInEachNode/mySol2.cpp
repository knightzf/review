#include "header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        unordered_map<int, Node*> m;
        function<void(Node*, int)> preorder = [&](Node* node, int depth)
        {
            if(!node) return;
            if(m.count(depth)) m[depth]->next = node;
            m[depth] = node;
            preorder(node->left, depth + 1);
            preorder(node->right, depth + 1);
        };
        preorder(root, 0);
        return root;
    }
};

int main()
{
    Solution s;
    
}