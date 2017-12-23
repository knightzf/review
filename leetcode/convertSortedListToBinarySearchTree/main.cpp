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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        std::vector<int> v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        if(v.empty())
        {
            return nullptr;
        }

        return impl(v, 0, v.size() - 1);
    }

    TreeNode* impl(const std::vector<int>& v, int start, int end)
    {
        if(start == end)
        {
            return new TreeNode(v[start]);
        }

        int mid = (start + end) / 2;

        TreeNode* node = new TreeNode(v[mid]);

        if(mid > start)
        {
            node->left = impl(v, start, mid - 1);
        }

        if(mid < end)
        {
            node->right = impl(v, mid + 1, end);
        }

        return node;
    }
};

void inorder(TreeNode* r)
{
    if(r == nullptr)
    {
        return;
    }

    inorder(r->left);
    std::cout<<r->val<<" ";
    inorder(r->right);
}
int main()
{
    Solution s;
    /*TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(15);
    TreeNode* d = new TreeNode(6);
    TreeNode* e = new TreeNode(20);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;*/
    //std::vector<int> a{1, 2, 4, 5, 3, 6, 7};

}
