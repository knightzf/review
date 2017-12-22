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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;

        std::queue<TreeNode*> s;
        s.push(root);

        int count = s.size();

        while(count)
        {
            std::vector<int> v;
            for(int i = 0; i < count; ++i)
            {
                TreeNode* node = s.front();
                if(node)
                {
                    v.push_back(node->val);

                    if(node->left)
                    {
                        s.push(node->left);
                    }

                    if(node->right)
                    {
                        s.push(node->right);
                    }
                }

                s.pop();
            }

            if(!v.empty())
                res.emplace_back(v);

            count = s.size();
        }

        return res;
    }
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
