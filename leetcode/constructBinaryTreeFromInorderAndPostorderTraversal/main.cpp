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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.empty())
        {
            return nullptr;
        }

        return impl(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* impl(vector<int>& inorder, vector<int>& postorder, int posIdx, int ordStart, int ordEnd)
    {
        int val = postorder[posIdx];

        TreeNode* root = new TreeNode(val);

        auto p = std::find(inorder.begin() + ordStart, inorder.begin() + ordEnd + 1, val);

        int leftSize = p - inorder.begin() - ordStart;
        int rightSize = inorder.begin() + ordEnd - p;

        if(rightSize)
        {
            TreeNode* right = impl(inorder, postorder, posIdx - 1, p + 1 - inorder.begin(), ordEnd);
            root->right = right;
        }

        if(leftSize)
        {
            TreeNode* left = impl(inorder, postorder, posIdx - rightSize - 1, ordStart, ordStart + leftSize - 1);
            root->left = left;
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
    //std::vector<int> a{1, 2, 4, 5, 3, 6, 7};
    std::vector<int> b{4, 2, 5, 1, 6, 3, 7};
    std::vector<int> c{4, 5, 2, 6, 7, 3, 1};
    TreeNode* r = s.buildTree(b, c);
    inorder(r);
    std::cout<<std::endl;
}
