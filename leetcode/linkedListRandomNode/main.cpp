#include "header.h"

class Solution {
private:
    ListNode* root;
    ListNode* current;
    long len = -1;
    long temp = 0;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
        current = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int r = rand();
        if(len == -1)
        {
            while(r > 0 && current)
            {
                --r;
                current = current->next;
                ++temp;
            }

            if(r == 0 && current)
            {
                return current->val;
            }
            else
            {
                len = temp;
                current = root;
                r %= len;
                while(r)
                {
                    advance();
                    --r;
                }
                return current->val;
            }
        }
        else
        {
            r %= len;
            while(r)
            {
                advance();
                --r;
            }
            return current->val;
        }
    }

    void advance()
    {
        if(current->next) current = current->next;
        else current = root;
    }
};

int main()
{
    //Solution s;
}
