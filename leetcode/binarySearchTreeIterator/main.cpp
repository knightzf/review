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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = s.top();
        int val = 0;
        if(!node->right)
        {
            val = node->val;
            s.pop();
        }
        else
        {
            val = node->val;
            TreeNode* right = node->right;
            s.pop();
            while(right)
            {
                s.push(right);
                right = right->left;
            }
        }

        return val;
    }
private:
    std::stack<TreeNode*> s;
};

int main()
{
    //Solution s;
}
