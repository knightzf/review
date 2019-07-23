#include "header.h"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        function<bool(TreeNode*, TreeNode*, bool)> f = [&](TreeNode* a, TreeNode* b, bool match) {
            if(!b) return a == b;
            if(!a) return false;
            if(a->val == b->val) {
                if(f(a->left, b->left, true) && f(a->right, b->right, true)) return true;
            }
            if(!match) {
                if(f(a->left, b, match) || f(a->right, b, match)) return true;
            }
            return false;
        };
        return f(s, t, false);
    }
};

int main()
{
    Solution s;
}