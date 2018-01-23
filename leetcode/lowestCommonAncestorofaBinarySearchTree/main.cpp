#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
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
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true)
        {
            if(root->left && isAncestor(root->left, p, q))
            {
                root = root->left;
            }
            else if(root->right && isAncestor(root->right, p, q))
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
    }

    bool isAncestor(TreeNode* n, TreeNode* p, TreeNode* q)
    {
        bool foundP = false;
        bool foundQ = false;

        std::queue<TreeNode*> queue;
        queue.push(n);

        while(!queue.empty())
        {
            TreeNode* t = queue.front();
            queue.pop();

            if(t == p) foundP = true;
            if(t == q) foundQ = true;

            if(foundP && foundQ) return true;

            if(t->left) queue.push(t->left);
            if(t->right) queue.push(t->right);
        }

        return false;
    }
};
int main() {
    Solution s;
}
