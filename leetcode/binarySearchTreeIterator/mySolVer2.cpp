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
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> s;
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
        int res = s.top()->val;

        TreeNode* n = s.top();
        s.pop();
        if(n->right)
        {
            s.push(n->right);
            n = n->right->left;
            while(n)
            {
                s.push(n);
                n = n->left;
            }
        }

        return res;
    }
};

int main() {
    //Solution s;
}
