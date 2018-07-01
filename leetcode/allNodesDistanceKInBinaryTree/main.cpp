#include "header.h"

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        findTarget(root, nullptr, target, parentMap);
        vector<int> res;
        TreeNode* node = target;
        int direction = 0;
        while(node && K >= 0)
        {
            findObject(node, K, direction, res);
            TreeNode* parent = parentMap[node];
            if(parent == nullptr) break;
            if(node == parent->left)
            {
                direction = 2;
            }
            else
            {
                direction = 1;
            }
            node = parent;
            --K;
        }
        return res;
    }

    void findObject(TreeNode* node, int K, int direction, vector<int>& res)
    {
        if(node == nullptr) return;
        if(K == 0)
        {
            res.push_back(node->val);
        }

        if(direction == 1)
        {
            findObject(node->left, K - 1, 0, res);
            return;
        }
        else if(direction == 2)
        {
            findObject(node->right, K - 1, 0, res);
            return;
        }

        impl(node, K, res);
    }

    void impl(TreeNode* node, int K, vector<int>& res)
    {
        if(node == nullptr || K < 0) return;
        if(K == 0)
        {
            res.push_back(node->val);
            return;
        }
        impl(node->left, K - 1 , res);
        impl(node->right, K - 1 , res);
    }

    void findTarget(TreeNode* root, TreeNode* parent, TreeNode* target,
                    unordered_map<TreeNode*, TreeNode*>& parentMap)
    {
        if(root == nullptr) return;

        parentMap[root] = parent;
        if(root == target) return;

        findTarget(root->left, root, target, parentMap);
        findTarget(root->right, root, target, parentMap);
    }
};

int main()
{
    Solution s;
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(2);
    a->left = b;
    b->left = c;
    b->right = d;
    const auto& r = s.distanceK(a, d, 1);
    cout<<r.size()<<endl;
}
