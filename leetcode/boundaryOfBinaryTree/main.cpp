#include "header.h"

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        bool hasLeft = (root && root->left);
        bool hasRight = (root && root->right);

        findBoundary(root, res);

        if(hasLeft || hasRight)
        {
            vector<int> t;
            inorder(root, t);
            auto iter = t.begin();
            auto iterEnd = t.end();
            if(hasLeft)
            {
                ++iter;
            }
            if(hasRight)
            {
                --iterEnd;
            }
            res.insert(res.end(), iter, iterEnd);
        }

        if(hasRight)
        {
            findBoundary(root, res, false);
        }

        return res;
    }

    void inorder(TreeNode* root, vector<int>& res)
    {
        if(root == nullptr) return;
        inorder(root->left, res);
        if(root->left == nullptr && root->right == nullptr)
        {
            res.emplace_back(root->val);
        }
        inorder(root->right, res);
    }

    void findBoundary(TreeNode* root, vector<int>& res, bool left = true)
    {
        if(root == nullptr) return;
        if((left && root->left == nullptr) || (!left && root->right == nullptr))
        {
            res.emplace_back(root->val);
            return;
        }

        vector<int> t;
        while(root)
        {
            t.emplace_back(root->val);

            if(root->left == nullptr && root->right == nullptr)
            {
                break;
            }

            if((left && root->left) || (!left && root->right == nullptr))
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        if(!left)
        {
            reverse(t.begin(), t.end());
            t.pop_back();
        }
        res.insert(res.end(), t.begin(), t.end());
    }
};

int main()
{
    Solution s;
}
