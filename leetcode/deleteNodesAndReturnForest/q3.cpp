#include "header.h"

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        function<void(TreeNode*, TreeNode*)> f = [&](TreeNode* node, TreeNode* p) {
            if(!node) return;
            if(s.count(node->val)) {
                if(p) {
                    if(node == p->left) p->left = nullptr;
                    else p->right = nullptr;
                }
                s.erase(node->val);
                f(node->left, nullptr);
                f(node->right, nullptr);
            } else {
                if(p == nullptr) res.emplace_back(node);
                f(node->left, node);
                f(node->right, node);
            }
        };
        f(root, nullptr);
        return res;
    }
};

int main()
{
    Solution s;
}

