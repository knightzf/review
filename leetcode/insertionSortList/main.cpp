#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* t = head->next;
        ListNode* newHead = head;
        newHead->next = nullptr;

        while(t)
        {
            ListNode* temp = t->next;
            newHead = insert(newHead, t);
            t = temp;
        }

        return newHead;
    }

private:
    ListNode* insert(ListNode* head, ListNode* node)
    {
        if(node == nullptr) return head;

        if(node->val <= head->val)
        {
            node->next = head;
            return node;
        }

        if(head->next == nullptr)
        {
            head->next = node;
            node->next = nullptr;
            return head;
        }

        ListNode* n = head;
        while(n)
        {
            if(n->val < node->val)
            {
                if(n->next)
                {
                    if(n->next->val >= node->val)
                    {
                        node->next = n->next;
                        n->next = node;
                        break;
                    }
                }
                else
                {
                    n->next = node;
                    node->next = nullptr;
                    break;
                }
            }

            n = n->next;
        }

        return head;
    }
};



int main()
{
    Solution s;
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    a->next = b; b->next = c;

    ListNode* r = s.insertionSortList(a);

    while(r)
    {
        std::cout<<r->val<<" ";
        r = r->next;
    }
    std::cout<<std::endl;

}
