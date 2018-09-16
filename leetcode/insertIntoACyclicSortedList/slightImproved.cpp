#include "header.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(head == nullptr)
        {
            node->next = node;
            return node;
        }
        
        Node* maxNode = head;
        Node* t = head;
        while(true)
        {
            if(t->val >= maxNode->val) {
                maxNode = t;
            }
            if(t->val <= insertVal && t->next->val >= insertVal) {
                node->next = t->next;
                t->next = node;
                break;
            }
            if(t->val <= insertVal && t->val >= t->next->val) {
                node->next = t->next;
                t->next = node;
                break;
            }
            t = t->next;
            if(t == head) {
                node->next = maxNode->next;
                maxNode->next = node;
                break;
            }
        }
        
        return head;
    }
};

int main() {
    //Solution s;
}
