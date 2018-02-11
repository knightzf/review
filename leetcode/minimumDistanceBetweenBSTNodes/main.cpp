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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        impl(root, minDiff);
        return minDiff;
    }
private:
    void impl(TreeNode* root, int& minDiff)
    {
        if(root == nullptr) return;

        if(root->left)
        {
            TreeNode* p = root->left;
            while(p->right) p = p->right;
            minDiff = std::min(minDiff, std::abs(root->val - p->val));

            impl(root->left, minDiff);
        }

        if(root->right)
        {
            TreeNode* p = root->right;
            while(p->left) p = p->left;
            minDiff = std::min(minDiff, std::abs(root->val - p->val));

            impl(root->right, minDiff);
        }
    }
};

int main() {
    Solution s;
}
