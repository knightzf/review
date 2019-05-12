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
        Node* node = root;        
        while(node)
        {
            Node t(0, nullptr, nullptr, nullptr);
            Node* curr = &t;
            while(node) {
                if(node->left) { curr->next = node->left; curr = curr->next; }
                if(node->right) { curr->next = node->right; curr = curr->next; }
                node = node->next;
            }
            node = t.next;
        }
        return root;
    }
};

int main()
{
    Solution s;
    
}