/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(!head)
                return nullptr;

            ListNode* slow = head;
            ListNode* fast = head;

            while(true)
            {            
                slow = slow->next;            
                if(!slow) return nullptr;

                fast = fast->next;
                if(!fast) return nullptr;

                fast = fast->next;
                if(!fast) return nullptr;

                if(slow == fast)
                    break;
            }   

            ListNode* begin = head;
            ListNode* meet = slow;

            while(begin != meet)
            {
                begin = begin->next;
                meet = meet->next;
            }

            return begin;
        }
};
