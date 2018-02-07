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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool foundP = false;
        return impl(root, p, foundP);
    }

    TreeNode* impl(TreeNode* root, TreeNode* p, bool& foundP)
    {
        if(root == nullptr) return nullptr;

        TreeNode* l = impl(root->left, p, foundP);
        if(l) return l;

        if(root == p)
        {
            foundP = true;
        }
        else
        {
            if(foundP) return root;
        }

        TreeNode* r = impl(root->right, p, foundP);
        if(r) return r;

        return nullptr;
    }
};
int main() {
    //Solution s;
}
