#include "header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto getLen = [](ListNode* t) {
            int i = 1;
            while(t = t->next) ++i;
            return i;
        };
        int m = getLen(l1), n = getLen(l2);
        if(m < n) {
            swap(m, n);
            swap(l1, l2);
        }
        ListNode* head = new ListNode(0);
        head->next = l1;
        ListNode* t = head->next;
        unordered_map<ListNode*, ListNode*> mm{{head, nullptr}};
        ListNode* pre = head;
        while(m > n) {
            mm.emplace(t, pre);
            pre = t;
            t = t->next;
            --m;
        }
        while(n--) {
            mm.emplace(t, pre);
            pre = t;
            t->val += l2->val;
            if(t->val > 9) {
                ListNode* tmp = t;
                while(tmp && tmp->val > 9) {
                    tmp->val %= 10;
                    if(mm[tmp]) {
                        tmp = mm[tmp];
                        tmp->val += 1;
                    }
                }
            }
            t = t->next;
            l2 = l2->next;
        }
        return head->val == 0 ? head->next : head;
    }
};

int main()
{
    //Solution s;
}