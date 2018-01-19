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

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int leftHeight = 0, rightHeight = 0;

        TreeNode* l = root, * r = root;

        while(l) {++leftHeight; l = l->left;}
        while(r) {++rightHeight; r = r->right;}

        if(leftHeight == rightHeight) return std::pow(2, leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};

int main() {
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b; a->right = c;
    s.countNodes(a);
}
