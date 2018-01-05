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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        int n = 0;
        ListNode* node = head;
        while(node)
        {
            ++n;
            node = node->next;
        }

        return impl(head, 0, n - 1);
    }

    ListNode* impl(ListNode* head, int startIdx, int endIdx)
    {
        //std::cout<<head->val<<" "<<startIdx<<" "<<endIdx<<std::endl;
        if(startIdx == endIdx) return head;

        int midIdx = (startIdx + endIdx) / 2;

        int temp = startIdx;
        ListNode* midNode = head;
        while(temp < midIdx)
        {
            midNode = midNode->next;
            ++temp;
        }
        ListNode* afterMid = midNode->next;
        midNode->next = nullptr;

        ListNode* left = impl(head, startIdx, midIdx);
        ListNode* right = impl(afterMid, midIdx + 1, endIdx);

        //std::cout<<"getting here"<<std::endl;
        return merge(left, right);
    }
private:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* head = nullptr;

        if(a->val <= b->val)
        {
            head = a;
            a = a->next;
        }
        else
        {
            head = b;
            b = b->next;
        }

        ListNode* node = head;

        while(a || b)
        {
            //std::cout<<(a == nullptr)<<" "<<(b == nullptr)<<std::endl;
            if(a && b)
            {
                if(a->val <= b->val)
                {
                    node->next = a;
                    a = a->next;
                }
                else
                {
                    node->next = b;
                    b = b->next;
                }
            }
            else if(a)
            {
                node->next = a;
                a = a->next;
            }
            else
            {
                node->next = b;
                b = b->next;
            }

            node = node->next;
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
    ListNode* d = new ListNode(0);
    a->next = b; b->next = c; c->next = d;

    ListNode* r = s.sortList(a);

    while(r)
    {
        std::cout<<r->val<<" ";
        r = r->next;
    }
    std::cout<<std::endl;

}
