#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node != nullptr)
        {
            ++n;
            node = node->next;
        }

        if(n <= 1) return true;

        int t = 0;
        node = head;
        ListNode* newLeftHead = nullptr;
        ListNode* newRightHead = nullptr;
        ListNode* prevNode = nullptr;
        while(t < n / 2)
        {
            ListNode* nextNode = node->next;
            node->next = prevNode;
            prevNode = node;
            node = nextNode;
            ++t;

            if(t == n / 2)
            {
                if(n % 2 == 0)
                {
                    newLeftHead = prevNode;
                    newRightHead = node;
                }
                else
                {
                    newLeftHead = prevNode;
                    newRightHead = node->next;
                }
            }
        }

        while(newLeftHead && newRightHead)
        {
            if(newLeftHead->val != newRightHead->val) return false;
            newLeftHead = newLeftHead->next;
            newRightHead = newRightHead->next;
        }

        return true;
    }
};

int main()
{
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(1);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    //a->next = e;
    std::cout<<s.isPalindrome(a)<<std::endl;
}
