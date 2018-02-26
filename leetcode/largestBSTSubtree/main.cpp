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
    int largestBSTSubtree(TreeNode* root) {
        int cnt = 0;
        isBST(root, INT_MIN, INT_MAX, cnt);

        return cnt;
    }
private:
    int isBST(TreeNode* root, int left, int right, int& cnt)
    {
        if(root == nullptr) return 0;

        if(root->val < left || root->val > right)
        {
            isBST(root, INT_MIN, INT_MAX, cnt);
            return -1;
        }
        else
        {
            int r1 = isBST(root->left, left, root->val - 1, cnt);
            int r2 = isBST(root->right, root->val + 1, right, cnt);

            if(r1 == -1 || r2 == -1)
            {
                if(r1 == -1)
                {
                    isBST(root->left, INT_MIN, INT_MAX, cnt);
                }
                if(r2 == -1)
                {
                    isBST(root->right, INT_MIN, INT_MAX, cnt);
                }

                return -1;
            }
            cnt = max(cnt, r1 + r2 + 1);
            return r1 + r2 + 1;
        }
    }
};


int main() {
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    a->left = b;
    std::cout<<s.largestBSTSubtree(a)<<std::endl;
}
