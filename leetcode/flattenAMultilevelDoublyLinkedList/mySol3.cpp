/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> f = [&](Node* node) {
            if(!node) return node;
            Node* last = nullptr;
            while(node) {
                last = node;
                if(!node->child) node = node->next;
                else {
                    Node* child = node->child, *next = node->next;
                    Node* end = f(child);
                    node->child = nullptr;
                    node->next = child;
                    child->prev = node;
                    end->next = next;
                    if(next) next->prev = end;
                    node = end;
                }
            }
            return last;
        };
        f(head);
        return head;
    }
};
