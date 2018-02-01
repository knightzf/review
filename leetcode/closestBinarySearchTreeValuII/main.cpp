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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        std::stack<int> inorder;
        std::stack<int> reverseInorder;

        traverse(root, target, false, inorder);
        traverse(root, target, true, reverseInorder);

        vector<int> res;
        while(k)
        {
            if(inorder.empty())
            {
                res.push_back(reverseInorder.top());
                reverseInorder.pop();
            }
            else if(reverseInorder.empty())
            {
                res.push_back(inorder.top());
                inorder.pop();
            }
            else if(target - inorder.top() < reverseInorder.top() - target)
            {
                res.push_back(inorder.top());
                inorder.pop();
            }
            else
            {
                res.push_back(reverseInorder.top());
                reverseInorder.pop();
            }

            --k;
        }

        return res;
    }

    void traverse(TreeNode* node, double target, bool rev, std::stack<int>& s)
    {
        if(node == nullptr) return;

        traverse(rev ? node->right : node->left, target, rev, s);

        if(!rev)
        {
            if(node->val >= target) return;
        }
        else
        {
            if(node->val < target) return;
        }

        s.push(node->val);

        traverse(rev ? node->left : node->right, target, rev, s);
    }
};

int main() {
    //Solution s;
}
