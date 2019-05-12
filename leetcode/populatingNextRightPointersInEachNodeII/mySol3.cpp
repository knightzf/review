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
        Node* node = root, *parent = nullptr;
        while(node)
        {
            Node* nextLevel = nullptr, *nextParent = nullptr;
            while(node) {
                if(!nextLevel) {
                    if(node->left) {
                        nextLevel = node->left;
                        nextParent = node;
                    }
                    else if(node->right) {
                        nextLevel = node->right;
                        nextParent = node;
                    }
                }
                if(parent) {
                    if(node == parent->left && parent->right) {
                        node->next = parent->right;
                    } else {
                        while(parent->next) {
                            parent = parent->next;
                            if(parent->left) {
                                node->next = parent->left;
                                break;
                            } else if(parent->right) {
                                node->next = parent->right;
                                break;
                            }
                        }
                    }
                }
                node = node->next;
            }
            node = nextLevel;
            parent = nextParent;
        }
        return root;
    }
};

int main()
{
    Solution s;
    
}