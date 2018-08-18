#include "header.h"

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, unordered_map<int, vector<TreeNode*>>> m;
        unordered_map<TreeNode*, int> childrenCnt;
        inorder(root, m, childrenCnt);

        vector<TreeNode*> res;
        unordered_set<TreeNode*> dups;

        for(const auto& p: m)
        {
            for(const auto& q : p.second)
            {
                const vector<TreeNode*>& v = q.second;
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

    void inorder(TreeNode* node, unordered_map<int, unordered_map<int, vector<TreeNode*>>>& m,
                 unordered_map<TreeNode*, int>& childrenCnt)
    {
        if(node == nullptr) return;

        inorder(node->left, m, childrenCnt);
        inorder(node->right, m, childrenCnt);

        int cnt = 0;
        if(childrenCnt.count(node->left)) cnt += childrenCnt[node->left] + 1;
        if(childrenCnt.count(node->right)) cnt += childrenCnt[node->right] + 1;

        childrenCnt[node] = cnt;
        m[node->val][childrenCnt[node]].push_back(node);
    }
};

int main() {
    Solution s;
}
