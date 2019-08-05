#include "header.h"

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* p = nullptr, *left = nullptr, *right = nullptr, *nodex = nullptr;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if(!node) return;
            inorder(node->left);
            if((node->left && node->left->val == x) ||
                (node->right && node->right->val == x)) p = node;
            if(node->val == x) {
                nodex = node;
                left = node->left;
                right = node->right;
            }
            inorder(node->right);
        };
        inorder(root);
        unordered_map<TreeNode*, int> cntMap;
        function<int(TreeNode*)> count = [&](TreeNode* node) {
            if(!node) return 0;
            if(cntMap.count(node)) return cntMap[node];
            int res = 1 + count(node->left) + count(node->right);
            cntMap[node] = res;
            return res;
        };
        cntMap[root] = count(root);
        if(p && cntMap[root] - cntMap[nodex] > cntMap[nodex]) return true;
        if(cntMap[left] > cntMap[root] - cntMap[left] || cntMap[right] > cntMap[root] - cntMap[right]) return true;
        return false;
    }
};

int main()
{
}
