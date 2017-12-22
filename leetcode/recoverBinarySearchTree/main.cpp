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
    void recoverTree(TreeNode* root)
    {
        prev = new TreeNode(INT_MIN);
        first = nullptr;
        second = nullptr;

        inorder(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    void inorder(TreeNode* node)
    {
        if(node == nullptr)
        {
            return;
        }

        inorder(node->left);

        if(first == nullptr && node->val < prev->val)
        {
            first = prev;
        }

        if(first != nullptr && node->val < prev->val)
        {
            second = node;
        }

        prev = node;

        inorder(node->right);
    }

private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
};

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

    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(-1);
    a->left = b;

}
