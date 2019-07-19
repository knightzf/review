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
        function<Node*(Node*, Node*)> f = [&](Node* node, Node* prior) {
            if(!node) return node;
            Node* pre = NULL;
            node->prev = prior;
            while(node) {
                pre = node;
                Node* t = node->next;
                if(node->child) {
                    node->next = node->child;
                    node->child = nullptr;
                    Node* r = f(node->next, node);
                    pre = r;
                    r->next = t;
                    if(t) t->prev = r;
                }
                node = t;
            }
            return pre;
        };
        f(head, nullptr);
        return head;
    }
};

int main()
{
    //Solution s;
}