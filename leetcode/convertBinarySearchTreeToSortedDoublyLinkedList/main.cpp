#include "header.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        const auto& r = f(root, nullptr);
        r.first->left = r.second;
        r.second->right = r.first;
        return r.first;
    }

    pair<Node*, Node*> f(Node* node, Node* parent) {
        if(!node) return make_pair(nullptr, nullptr);
        const auto& left = f(node->left, node);
        const auto& right = f(node->right, node);
        node->left = left.second ? left.second : node->left;
        node->right = right.first ? right.first : node->right;
        Node* r1 = left.first ? left.first : node;
        Node* r2 = right.second ? right.second : node;
        if(parent) {
            if(node == parent->left) {
                r2->right = parent;
            } else {
                r1->left = parent;
            }
        }
        return make_pair(r1, r2);
    }
};

int main()
{
    Solution s;
}