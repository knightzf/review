#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
        ListNode* result = new ListNode(0);
		
		ListNode* node = result;
		bool first = true;
		bool carry = false;
		
		while(l1 || l2 || (!l1 & !l2 & carry))
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (carry ? 1 : 0);
			carry = sum > 9;
			sum = carry ? (sum - 10) : sum;
			
			if(first)
			{
				node->val = sum;
				first = false;
			}
			else
			{
				ListNode* temp = new ListNode(sum);
				node->next = temp;
				node = temp;
			}
			
			if(l1) l1 = l1->next;
			if(l2) l2 = l2->next;
		}
		
		return result;
    }
};

int main()
{
	return 0;
}