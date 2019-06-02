#include "header.h"

class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* t = s.top();
        s.pop();
        if(t->right)
        {
            TreeNode* tt = t->right;
            while(tt) {
                s.push(tt);
                tt = tt->left;
            }
        }
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

int main()
{
    //Solution s;
}