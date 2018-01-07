#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        int level = 0;
        if(root == nullptr) return nullptr;
        return impl(root, root->left, root->right);
    }

    TreeNode* impl(TreeNode* root, TreeNode* left, TreeNode* right) {
        if(!left && !right) return root;

        TreeNode* newLeft = left->left;
        TreeNode* newRight = left->right;

        //std::cout<<root->val<<std::endl;
        left->right = root;
        left->left = right;
        if(level == 0)
        {
            root->left = nullptr;
            root->right = nullptr;
        }
        ++level;
        return impl(left, newLeft, newRight);
    }

private:
    int level;
};

int main()
{
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    a->left = b;
    s.upsideDownBinaryTree(a);
}
