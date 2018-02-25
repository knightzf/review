#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* root = head->next;

        ListNode* odd = head;
        ListNode* even = root;

        while(true)
        {
            if(!even) break;
            ListNode* nextOdd = even->next;
            odd->next = nextOdd;
            if(!nextOdd) break;
            odd = nextOdd;

            ListNode* nextEven = nextOdd->next;
            even->next = nextEven;
            even = nextEven;
        }

        odd->next = root;
        return head;
    }
};


int main() {
    Solution s;
}
