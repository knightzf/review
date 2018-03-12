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
    vector<vector<int>> findLeaves(TreeNode* root) {
        std::map<int, vector<int>> m;
        impl(root, m);
        vector<vector<int>> res;
        for(auto i = m.begin(); i != m.end(); ++i)
        {
            res.push_back(i->second);
        }
        return res;
    }

    int impl(TreeNode* root, std::map<int, vector<int>>& m)
    {
        if(root == nullptr) return -1;
        if(!root->left && !root->right) {
            m[0].push_back(root->val);
            return 0;
        }

        int depth = max(impl(root->left, m), impl(root->right, m)) + 1;
        m[depth].push_back(root->val);
        return depth;
    }
};

int main() {
    Solution s;
}
