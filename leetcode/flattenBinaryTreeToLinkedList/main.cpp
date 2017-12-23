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
    void flatten(TreeNode* root)
    {
        if(!root)
            return;

        std::stack<TreeNode*> s;
        s.push(root);

        TreeNode* prev = nullptr;

        while(!s.empty())
        {
            TreeNode* node = s.top();

            if(prev)
            {
                prev->left = nullptr;
                prev->right = node;
            }

            prev = node;

            s.pop();

            if(node->right)
            {
                s.push(node->right);
            }

            if(node->left)
            {
                s.push(node->left);
            }
        }
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

}
