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
        function<void(Node*, Node*)> preorder = [&](Node* node, Node* parent)
        {
            if(!node) return;
            if(parent) {
                if(node == parent->left) node->next = parent->next;
                else node->next = parent->next->left;
            }
            preorder(node->left, node);
            preorder(node->right, node);
        };
        preorder(root, 0);
        return root;
    }
};

int main()
{
    Solution s;
    
}