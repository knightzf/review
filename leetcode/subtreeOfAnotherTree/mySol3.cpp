#include "header.h"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        function<bool(TreeNode*, TreeNode*)> sameTree = [&](TreeNode* a, TreeNode* b) {
            if(a == nullptr && b == nullptr) return true;
            if(!a || !b) return false;
            if(a->val != b->val) return false;
            return sameTree(a->left, b->left) && sameTree(a->right, b->right);
        };
        if(!s) return s == t;
        return sameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main()
{
    Solution s;
}