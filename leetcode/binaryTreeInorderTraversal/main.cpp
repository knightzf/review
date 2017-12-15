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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if(root == nullptr)
        {
            return res;
        }

        TreeNode* t = root;

        std::stack<TreeNode*> s;
        s.push(t);

        while(!s.empty())
        {
            TreeNode* curr = s.top();
            if(curr->left)
            {
                s.push(curr->left);
                curr->left = nullptr;
            }
            else
            {
                res.push_back(curr->val);
                s.pop();
                if(curr->right)
                {
                    s.push(curr->right);
                    curr->right = nullptr;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->right = b;
    b->left = c;

    const auto& r = s.inorderTraversal(a);
    for(const auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
