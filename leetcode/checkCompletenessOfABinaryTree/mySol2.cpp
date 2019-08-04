#include "header.h"

class Solution {
private:
    int maxDepth = 0;
    bool seenFirstIncomplete = false;
public:
    bool isCompleteTree(TreeNode* root, int d = 0) {
        if(!root) {
            if(maxDepth == 0) maxDepth = d;
            if(d < maxDepth) seenFirstIncomplete = true;
            if((!seenFirstIncomplete && d == maxDepth) ||
               (seenFirstIncomplete && d == maxDepth - 1)) return true;
            return false;
        }
        return isCompleteTree(root->left, d + 1) && isCompleteTree(root->right, d + 1);
    }
};

int main()
{
    Solution s;
}