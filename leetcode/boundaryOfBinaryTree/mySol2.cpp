#include "header.h"

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* node = root;
        res.push_back(node->val);
        if(node->left) {
            vector<TreeNode*> s;
            while(node) {
                s.push_back(node);
                if(node->left) node = node->left;
                else node = node->right;
            }
            for(int i = 1, n = s.size(); i < n - 1; ++i) {
                res.push_back(s[i]->val);
            }
        }
        function<void(TreeNode*)> f = [&](TreeNode* node) {
            if(!node) return;
            f(node->left);
            if(!node->left && !node->right && node != root) res.push_back(node->val);
            f(node->right);
        };
        f(root);
        node = root;
        if(node->right) {
            stack<TreeNode*> s;
            while(node) {
                s.push(node);
                if(node->right)
                node = node->right;
                else node = node->left;
            }
            if(!s.empty() && !s.top()->left && !s.top()->right) s.pop();
            while(!s.empty()) {
                if(s.top() != root)
                    res.push_back(s.top()->val);
                s.pop();
            }
        }
        return res;
    }
};

int main()
{
    //Solution s;
}