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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;

        std::deque<TreeNode*> q;
        q.push_back(root);
        int qsize = q.size();

        while(qsize)
        {
            res.push_back(q.back()->val);
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode* n = q.front();
                q.pop_front();

                if(n->left) q.push_back(n->left);
                if(n->right) q.push_back(n->right);
            }

            qsize = q.size();
        }

        return res;
    }
};

int main() {
    Solution s;
}
