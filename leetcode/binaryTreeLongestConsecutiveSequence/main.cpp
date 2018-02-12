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
    int longestConsecutive(TreeNode* root) {
        int maxCount = 0;
        impl(root, maxCount);
        return maxCount;
    }

    int impl(TreeNode* root, int& maxCount)
    {
        if(root == nullptr) return 0;

        int t1 = 1, t2 = 1;
        if(root->left && root->val + 1 == root->left->val)
        {
            t1 += impl(root->left, maxCount);
        }

        if(root->right && root->val + 1 == root->right->val)
        {
            t2 += impl(root->right, maxCount);
        }

        maxCount = max(maxCount, max(t1, t2));

        return max(t1, t2);
    }
};

int main() {
    Solution s;
}
