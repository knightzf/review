#include "header.h"

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        if(impl(root, voyage, res, 0, voyage.size())) return res;
        return {-1};
    }

    bool impl(TreeNode* node, const vector<int>& voyage, vector<int>& res, int startIdx, int endIdx)
    {
        if(node->val != voyage[startIdx]) return false;

        int i = startIdx + 1;
        if(i == endIdx) return true;

        int leftIdx, rightIdx;
        bool found = false;
        if(node->left && voyage[i] == node->left->val)
        {
            if(node->right)
            {
                for(; i < endIdx; ++i)
                {
                    if(voyage[i] == node->right->val) 
                    {
                        found = true;
                        break;
                    }
                }

                if(found == false) return false;

                return impl(node->left, voyage, res, startIdx + 1, i) &&
                       impl(node->right, voyage, res, i, endIdx);
            }
            else
            {
                return impl(node->left, voyage, res, startIdx + 1, endIdx);
            }  
        }
        else if(node->right && voyage[i] == node->right->val)
        {
            if(node->left)
            {
                res.push_back(node->val);
                for(; i < endIdx; ++i)
                {
                    if(voyage[i] == node->left->val)
                    {
                        found = true;
                        break;
                    }
                }

                if(found == false) return false;

                return impl(node->left, voyage, res, i, endIdx) &&
                       impl(node->right, voyage, res, startIdx + 1, i);
            }
            else
            {
                return impl(node->right, voyage, res, startIdx + 1, endIdx);
            }  
        }

        return false;
    }
};

int main()
{
    Solution s;
}

