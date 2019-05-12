#include "header.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* t = head;
        while(t)
        {
            ++size;
            t = t->next;
        }

        t = head;

        function<TreeNode*(int, int)> f = [&](int startIdx, int endIdx)
        {
            if(startIdx == endIdx) return (TreeNode*)0;
            int midIdx = (startIdx + endIdx) / 2;
            TreeNode* left = f(startIdx, midIdx);
            TreeNode* node = new TreeNode(t->val);
            t = t->next;
            TreeNode* right = f(midIdx + 1, endIdx);
            node->left = left;
            node->right = right;
            return node;
        };

        return f(0, size);
    }
};

int main()
{
    Solution s;
}