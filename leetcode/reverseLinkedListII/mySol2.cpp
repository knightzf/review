#include "header.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = nullptr, *newHead = head;
        ListNode* start = nullptr, *prior = nullptr;
        int i = 1;
        while(i <= n)
        {
            if(i == m - 1) prev = head;

            if(m <= i && i <= n) {
                if(i == m) start = head;
                else if(i == n) {
                    start->next = head->next;
                    if(prev) prev->next = head;
                    else newHead = head;
                }

                ListNode* next = head->next;
                if(i > m) head->next = prior;
                prior = head;
                head = next;
            }
            else head = head->next;
            ++i;
        }

        return newHead;
    }
};

int main()
{
    Solution s;
}