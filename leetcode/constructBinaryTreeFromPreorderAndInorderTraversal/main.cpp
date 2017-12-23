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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.empty())
            return nullptr;
        return impl(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode* impl(vector<int>& preorder, vector<int>& inorder, int preIdx, int ordStart, int ordEnd)
    {
        TreeNode* root = new TreeNode(preorder[preIdx]);

        auto p = std::find(inorder.begin() + ordStart, inorder.begin() + ordEnd + 1, preorder[preIdx]);

        //std::cout<<preIdx<<" "<<*(inorder.begin() + ordStart)<<" "<<*(inorder.begin() + ordEnd)<<" "<<
        //    preorder[preIdx]<<std::endl;

        int leftSize = p - inorder.begin() - ordStart;
        int rightSize = inorder.begin() + ordEnd - p;

        //std::cout<<leftSize<<" "<<rightSize<<std::endl;

        if(leftSize)
        {
            TreeNode* left = impl(preorder, inorder, preIdx + 1, ordStart, ordStart + leftSize - 1);
            root->left = left;
        }

        if(rightSize)
        {
            //std::cout<<"right "<<preIdx<<" "<<preorder[preIdx + leftSize + 1]<<std::endl;
            TreeNode* right = impl(preorder, inorder, preIdx + leftSize + 1, p + 1 - inorder.begin(), ordEnd);
            root->right = right;
        }

        return root;
    }
};

void inorder(TreeNode* r)
{
    if(r == nullptr)
    {
        return;
    }

    inorder(r->left);
    std::cout<<r->val<<" ";
    inorder(r->right);
}
int main()
{
    Solution s;
    /*TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(15);
    TreeNode* d = new TreeNode(6);
    TreeNode* e = new TreeNode(20);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;*/
    std::vector<int> a{1, 2, 4, 5, 3, 6, 7};
    std::vector<int> b{4, 2, 5, 1, 6, 3, 7};
    TreeNode* r = s.buildTree(a, b);
    inorder(r);
    std::cout<<std::endl;
}
