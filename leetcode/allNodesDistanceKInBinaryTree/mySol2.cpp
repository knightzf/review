#include "header.h"

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> m;
        function<void(TreeNode*, TreeNode*)> f = [&](TreeNode* node, TreeNode* p) {
            if(!node) return;
            m[node] = p;
            if(node == target) return;
            f(node->left, node);
            f(node->right, node);
        };
        f(root, nullptr);
        TreeNode* child = nullptr, *node = target;
        int dis = 0;
        vector<int> res;
        function<void(TreeNode*, int)> g = [&](TreeNode* node, int distance) {
            if(!node || distance > K) return;
            if(distance == K) res.push_back(node->val);
            g(node->left, distance + 1);
            g(node->right, distance + 1);
        };
        while(node && dis <= K) {
            if(dis == K) res.push_back(node->val);
            if(!child || node->left == child) g(node->right, dis + 1);
            if(!child || node->right == child) g(node->left, dis + 1);
            child = node;
            node = m[node];
            ++dis;
        }
        return res;
    }
};

int main()
{
    Solution s;
}