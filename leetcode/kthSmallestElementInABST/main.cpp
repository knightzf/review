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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        while(root)
        {
            s.push(root);
            root = root->left;
        }

        int cnt = 0;
        while(!s.empty())
        {
            TreeNode* n = s.top();
            s.pop();
            ++cnt;

            if(cnt == k) return n->val;

            if(n->right)
            {
                n = n ->right;
                while(n)
                {
                    s.push(n);
                    n = n->left;
                }
            }
        }

        return 0;
    }
};

int main() {
    Solution s;

}
