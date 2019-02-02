#include "header.h"

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> m;
        vector<TreeNode*> leaf;

        function<void(TreeNode*, TreeNode*)> f = [&](TreeNode* p, TreeNode* node)
        {
            if(node == nullptr) return;

            m[node] = p;

            if(node->left == nullptr && node->right == nullptr)
            {
                leaf.push_back(node);
                return;
            }

            f(node, node->left);
            f(node, node->right);
        };

        f(nullptr, root);

        string res;

        for(auto p : leaf)
        {
            string t;
            while(true)
            {
                t += char('a' + p->val);
                if(m[p] == nullptr) break;
                p = m[p];
            }

            if(res.empty()) res = t;
            else res = min(res, t);
        }
        return res;
    }
};

int main()
{
    //Solution s;
}
