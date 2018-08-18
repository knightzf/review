#include "header.h"

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>> m;
        inorder(root, m);

        vector<TreeNode*> res;
        unordered_set<TreeNode*> dups;

        for(const auto& p: m)
        {
            const vector<TreeNode*>& v = p.second;
            for(int i = 0, n = v.size(); i < n - 1; ++i)
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if(equalTree(v[i], v[j]))
                    {
                        if(dups.count(v[i]) == 0)
                            res.push_back(v[i]);
                        dups.insert(v[i]);
                        dups.insert(v[j]);
                    }
                }
            }
        }
        return res;
    }

    bool equalTree(TreeNode* i, TreeNode* j)
    {
        if(i == nullptr && j == nullptr) return true;
        if(i == nullptr || j == nullptr) return false;

        if(i->val != j->val) return false;
        return equalTree(i->left, j->left) && equalTree(i->right, j->right);
    }

    void inorder(TreeNode* node, unordered_map<int, vector<TreeNode*>>& m)
    {
        if(node == nullptr) return;

        inorder(node->left, m);
        m[node->val].push_back(node);
        inorder(node->right, m);
    }
};

int main() {
    Solution s;
}
