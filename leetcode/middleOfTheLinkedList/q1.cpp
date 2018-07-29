#include "header.h"

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        unordered_map<int, ListNode*> m;
        int i = 0;
        while(head)
        {
            m[i] = head;
            i++;
            head = head->next;
        }

        return m[i / 2];
    }
};

int main()
{
    Solution s;
}
