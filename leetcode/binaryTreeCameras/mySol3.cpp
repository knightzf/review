class Solution {
public:
    int minCameraCover(TreeNode* root) {
        map<pair<TreeNode*, int>, int> m;
        function<int(TreeNode*, int)> f = [&](TreeNode* node, int val) {
            if(!node) return 0;
            auto p = make_pair(node, val);
            if(m.count(p)) return m[p];
            int res = 1000;
            switch(val) {
                case 0:
                    if(node->left && node->right) {
                        res = min(res, f(node->left, 2) + f(node->right, 2));
                        res = min(res, f(node->left, 2) + f(node->right, 0));
                        res = min(res, f(node->left, 0) + f(node->right, 2));
                    } else if(node->left) {
                        res = f(node->left, 2);
                    } else if(node->right) {
                        res = f(node->right, 2);
                    } else {
                        return res;
                    }
                    break;
                case 1:
                    res = min(res, f(node->left, 2) + f(node->right, 2));
                    res = min(res, f(node->left, 0) + f(node->right, 0));
                    res = min(res, f(node->left, 2) + f(node->right, 0));
                    res = min(res, f(node->left, 0) + f(node->right, 2));
                    break;
                case 2:
                    res = min(res, f(node->left, 2) + f(node->right, 2));
                    res = min(res, f(node->left, 1) + f(node->right, 1));
                    res = min(res, f(node->left, 1) + f(node->right, 2));
                    res = min(res, f(node->left, 2) + f(node->right, 1));
                    break;
            }
            m[p] = res + (val == 2 ? 1 : 0);
            return m[p];
        };
        return min(f(root, 0), f(root, 2));
    }
};
