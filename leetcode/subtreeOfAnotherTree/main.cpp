#include "header.h"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return impl(s, t);
    }

    bool impl(TreeNode* s, TreeNode* t, bool matchMode = false)
    {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr || t == nullptr) return false;
        if(s->val == t->val)
        {
            if(impl(s->left, t->left, true) && impl(s->right, t->right, true))
                return true;
        }
        else if(matchMode) return false;

        return impl(s->left, t) || impl(s->right, t);
    }
};

int main()
{
    Solution s;
}
