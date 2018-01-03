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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if(root == nullptr) return res;

        std::stack<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.top();
            res.push_back(node->val);

            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);

            q.pop();
        }

        return res;
    }
};


int main()
{
    Solution s;
}
