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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
        {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }

        if(fast == nullptr)
        {
            return head->next;
        }

        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* target = slow->next;
        if(target->next == nullptr)
        {
            slow->next = nullptr;
        }
        else
        {
            ListNode* post = target->next;
            slow->next = post;
        }

        return head;
    }
};

int main()
{
    Solution sol;

    return 0;
}
