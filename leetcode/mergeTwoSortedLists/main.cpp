#include "header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* node = head;
        while(l1 || l2)
        {
            int val;
            if(l1 && l2)
            {
                if(l1->val <= l2->val) {
                    val = l1->val;
                    l1 = l1->next;
                } else {
                    val = l2->val;
                    l2 = l2->next;
                }
            }
            else if(l1)
            {
                val = l1->val;
                l1 = l1->next;
            }
            else
            {
                val = l2->val;
                l2 = l2->next;
            }
            
            if(!head) {
                head = new ListNode(val);
                node = head;
            } else {
                node->next = new ListNode(val);
                node = node->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;
}