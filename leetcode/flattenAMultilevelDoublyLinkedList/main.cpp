#include "header.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* res = head;
        stack<Node*> s;
        Node* pre = nullptr;
        while(head) {
            head->prev = pre;
            pre = head;
            if(head->child) {
                if(head->next)
                s.push(head->next);
                head->next = head->child;
                head->child = nullptr;
                head = head->next;
            }
            else if(head->next == nullptr && !s.empty()) {
                head->next = s.top();
                head = s.top();
                s.pop();
            } else head = head->next;
        }
        return res;
    }
};

int main()
{
    //Solution s;
}