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
        Node *dummy = new Node(0, nullptr, nullptr), *prev = dummy;
        function<void(Node*)> inorder = [&](Node* node) {
            if(!node) return;
            inorder(node->left);
            prev->right = node;
            node->left = prev;
            prev = node;
            inorder(node->right);
        };
        inorder(root);
        if(prev != dummy) {
            prev->right = dummy->right;
            dummy->right->left = prev;
        }
        return dummy->right;
    }
};

int main()
{
    Solution s;
}