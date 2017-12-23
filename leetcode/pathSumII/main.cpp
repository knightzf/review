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

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> res;

        if(!root)
        {
            return res;
        }

        int remain = sum - root->val;

        if(remain == 0 && !root->left && !root->right)
        {
            res.push_back({root->val});
            return res;
        }

        if(root->left)
        {
            const auto& r = pathSum(root->left, remain);
            for(const auto& i : r)
            {
                vector<int> a{root->val};
                a.insert(a.end(), i.begin(), i.end());
                res.emplace_back(a);
            }
        }

        if(root->right)
        {
            const auto& r = pathSum(root->right, remain);
            for(const auto& i : r)
            {
                vector<int> a{root->val};
                a.insert(a.end(), i.begin(), i.end());
                res.emplace_back(a);
            }
        }

        return res;
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
