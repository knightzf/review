#include "header.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;

        int level = 0;
        vector<TreeNode*> v{root};
        while(!v.empty())
        {
            vector<TreeNode*> t;
            for(int i = 0; i < v.size(); ++i)
            {
                TreeNode* node = v[i];
                if(node->left)
                {
                    if(t.size() != i * 2) return false;
                    t.push_back(node->left);
                }

                if(node->right)
                {
                    if(t.size() != i * 2 + 1) return false;
                    t.push_back(node->right);
                }
            }

            ++level;

            if(t.size() != (1 << level))
            {
                for(auto& node : t)
                {
                    if(node->left || node->right) return false;
                }
                return true;
            }
            
            v = t;
        }

        return true;
    }
};

int main()
{
    Solution s;
}
